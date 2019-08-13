/******************************************************************************
Description: parsing xml tag content into list
    such as string has format .... <xx>yyy<xx> ..., with single layer
    insert xx-yyy into a list
******************************************************************************/ 

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>
#include <stdarg.h>

/* ------------------------------ 声明区域 --------------------------------- */

// list node
typedef struct node{
    char* tagName;
    char* content;
    struct node* next;
} T_NODE, *PT_NODE;

typedef enum returnType {
    FAIL = 0,
    SUCCESS,
} E_RETURN_TYPE;
    
typedef enum boolType {
    FALSE = 0,
    TRUE,
} E_BOOL_TYPE;

typedef struct stringObj{
    char* szStr;
    int iLen;
    int iIndex;
    E_BOOL_TYPE bIsMalloc;
    int iMallocSize;
} T_STRING_OBJ, *PT_STRING_OBJ;

void MyPrintf(char* fmt, ...);
char* DupSubStr(char* str, int start, int end);
void StopWithMsg(char* msg);

typedef enum xmlParseMachineState {
    XML_PARSE_STATE_NULL = 0,
    XML_PARSE_STATE_STARTTAG,
    XML_PARSE_STATE_CONTENT,
    XML_PARSE_STATE_ENDTAG,
} E_XML_PARSE_STATE;

typedef struct xmlParseStateMachine{
    E_XML_PARSE_STATE eParseState;
    T_STRING_OBJ tStartTag;
    T_STRING_OBJ tEndTag;
    T_STRING_OBJ tContent;
} T_XML_PARSE_STATE_MACHINE, *PT_XML_PARSE_STATE_MACHINE;

// rule function definition
typedef E_BOOL_TYPE (*IsEventTriggered)(char cCurrentChar);
typedef E_RETURN_TYPE (*EventHandler)(char cCurrentChar, PT_XML_PARSE_STATE_MACHINE ptStateMachine, PT_NODE ptHead);

// state change rule: parse state -> event -> target state -> doaction
typedef struct stateChangeRule {
    E_XML_PARSE_STATE eCurrentState;
    IsEventTriggered isEventTriggered;
    E_XML_PARSE_STATE eTransferState;
    EventHandler eventhandler; 
} T_STATE_CHANGE_RULE, *PT_STATE_CHANGE_RULE;

void InitXMLParseStateMachine(PT_XML_PARSE_STATE_MACHINE ptXMLParseStateMachine);
void FreeXMLParseStateMachine(PT_XML_PARSE_STATE_MACHINE ptXMLParseStateMachine);

typedef struct xmlNode{
    char* tagName;
    char* content;
} T_XML_NODE, *PT_XML_NODE;

E_BOOL_TYPE IsEventTriggered_StateNull_Jump2StartTag(char cCurrentChar);
E_RETURN_TYPE EventHandler_StateNull_Jump2StartTag(char cCurrentChar, PT_XML_PARSE_STATE_MACHINE ptStateMachine, PT_NODE ptHead);

E_BOOL_TYPE IsEventTriggered_StateNull_KeepState(char cCurrentChar);
E_RETURN_TYPE EventHandler_StateNull_KeepState(char cCurrentChar, PT_XML_PARSE_STATE_MACHINE ptStateMachine, PT_NODE ptHead);

E_BOOL_TYPE IsEventTriggered_StateStartTag_Jump2Content(char cCurrentChar);
E_RETURN_TYPE EventHandler_StateStartTag_Jump2Content(char cCurrentChar, PT_XML_PARSE_STATE_MACHINE ptStateMachine, PT_NODE ptHead);

E_BOOL_TYPE IsEventTriggered_StateStartTag_KeepState(char cCurrentChar);
E_RETURN_TYPE EventHandler_StateStartTag_KeepState(char cCurrentChar, PT_XML_PARSE_STATE_MACHINE ptStateMachine, PT_NODE ptHead);

E_BOOL_TYPE IsEventTriggered_StateContent_Jump2EndTag(char cCurrentChar);
E_RETURN_TYPE EventHandler_StateContent_Jump2EndTag(char cCurrentChar, PT_XML_PARSE_STATE_MACHINE ptStateMachine, PT_NODE ptHead);

E_BOOL_TYPE IsEventTriggered_StateContent_KeepState(char cCurrentChar);
E_RETURN_TYPE EventHandler_StateContent_KeepState(char cCurrentChar, PT_XML_PARSE_STATE_MACHINE ptStateMachine, PT_NODE ptHead);

E_BOOL_TYPE IsEventTriggered_StateEndTag_Jump2Null(char cCurrentChar);
E_RETURN_TYPE EventHandler_StateEndTag_Jump2Null(char cCurrentChar, PT_XML_PARSE_STATE_MACHINE ptStateMachine, PT_NODE ptHead);

E_BOOL_TYPE IsEventTriggered_StateEndTag_KeepState(char cCurrentChar);
E_RETURN_TYPE EventHandler_StateEndTag_KeepState(char cCurrentChar, PT_XML_PARSE_STATE_MACHINE ptStateMachine, PT_NODE ptHead);



/* ------------------------------ 全局变量 --------------------------------- */
T_STATE_CHANGE_RULE g_stateChangeTable[] = {
    {
        XML_PARSE_STATE_NULL,
        IsEventTriggered_StateNull_Jump2StartTag,
        XML_PARSE_STATE_STARTTAG,
        EventHandler_StateNull_Jump2StartTag
    },
    {
        XML_PARSE_STATE_NULL,
        IsEventTriggered_StateNull_KeepState,
        XML_PARSE_STATE_NULL,
        EventHandler_StateNull_KeepState
    },
    {
        XML_PARSE_STATE_STARTTAG,
        IsEventTriggered_StateStartTag_Jump2Content,
        XML_PARSE_STATE_CONTENT,
        EventHandler_StateStartTag_Jump2Content
    },
    {
        XML_PARSE_STATE_STARTTAG,
        IsEventTriggered_StateStartTag_KeepState,
        XML_PARSE_STATE_STARTTAG,
        EventHandler_StateStartTag_KeepState
    },
    {
        XML_PARSE_STATE_CONTENT,
        IsEventTriggered_StateContent_Jump2EndTag,
        XML_PARSE_STATE_ENDTAG,
        EventHandler_StateContent_Jump2EndTag
    },
    {
        XML_PARSE_STATE_CONTENT,
        IsEventTriggered_StateContent_KeepState,
        XML_PARSE_STATE_CONTENT,
        EventHandler_StateContent_KeepState
    },
    {
        XML_PARSE_STATE_ENDTAG,
        IsEventTriggered_StateEndTag_Jump2Null,
        XML_PARSE_STATE_NULL,
        EventHandler_StateEndTag_Jump2Null
    },
    {
        XML_PARSE_STATE_ENDTAG,
        IsEventTriggered_StateEndTag_KeepState,
        XML_PARSE_STATE_ENDTAG,
        EventHandler_StateEndTag_KeepState
    }
};

/* ------------------------------ 公共函数 --------------------------------- */
// MyPrintf == puts + format args
void MyPrintf(char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
   
    printf("\r\n");
}

// 创建新的存储空间， 拷贝字符串的子串
char* DupSubStr(char* str, int start, int end)
{
    char* newStr = NULL;
   
    // sub string len 开区间 计算子串长度
    int len = end - start + 1;
   
    // regarding ending zero
    len++;
   
    newStr = (char*)malloc( sizeof(char)*len );
   
    if ( NULL == newStr )
    {
        return NULL;
    }
   
    newStr[len-1] = '\0';
    strncpy(newStr, str+start, len-1);
   
    return newStr;
}

/* duplicates a string */  
char *dupstr(const char *s)  
{  
  char *p = malloc(strlen(s) + 1);  
  
  if (p)  
    strcpy(p, s);  
  return p;  
}  

void StopWithMsg(char* msg)
{
    puts(msg);
    assert(0);
}

// 释放字符串指针 
void FreeStrPoint(char** pszStr)
{
    char* szStr = *pszStr;
    
    if ( szStr )
    {
        free(szStr);
    }
    
    *pszStr = NULL;
}

/* ------------------------------ 链表函数 --------------------------------- */
void FreeNode(PT_NODE* pptNode)
{
    PT_NODE ptNode = *pptNode;
    
    FreeStrPoint(&(ptNode->tagName));
    FreeStrPoint(&(ptNode->content));
    
    free(ptNode);
    
    *pptNode = NULL;
}

void FreeList(PT_NODE ptHeadNode)
{
    PT_NODE ptCurNode = ptHeadNode->next;
    PT_NODE ptNextNode = NULL;
    
    while(ptCurNode)
    {
        ptNextNode = ptCurNode->next;
        
        FreeNode(&ptCurNode);

        ptCurNode = ptNextNode;
    }
}

E_BOOL_TYPE Insert2List(PT_NODE ptHeadNode, char* tagName, char* content)
{
    PT_NODE ptNode = NULL;
    PT_NODE ptFirst = NULL;
   
    ptNode = (PT_NODE) malloc(sizeof(T_NODE));
    if ( ptNode == NULL )
    {
        return FAIL;
    }
   
    ptNode->tagName = (char*)dupstr(tagName);
       if ( !ptNode->tagName )
       {
           FreeNode(&ptNode);
           return FAIL;
    }

    ptNode->content = (char*)dupstr(content);
       if ( !ptNode->content )
       {
           FreeNode(&ptNode);
           return FAIL;
    }
   
    ptFirst = ptHeadNode->next;
    ptHeadNode->next = ptNode;
    ptNode->next = ptFirst;
    
    return SUCCESS;
}

void PrintList(PT_NODE ptHeadNode)
{
    PT_NODE ptCurNode = NULL;
    MyPrintf("---- list printing begin -----");
 
     ptCurNode = ptHeadNode->next;
    while(ptCurNode)
    {
        MyPrintf("node tagname is %s", ptCurNode->tagName);
        MyPrintf("node content is %s", ptCurNode->content);
        
        ptCurNode = ptCurNode->next;
    }
   
    MyPrintf("---- list printing end -----");
}

void AssertList(PT_NODE ptHeadNode, T_XML_NODE    xmlArr[]){
    int index = 0;
    PT_NODE ptCurNode = ptHeadNode->next;
   
    while(ptCurNode)
    {
        if ( xmlArr[index].tagName == NULL )
        {
            StopWithMsg("xmlArr reach top, but list not over.");
            return;
        }
       
        if ( strcmp(ptCurNode->tagName, xmlArr[index].tagName) == 0
            && strcmp(ptCurNode->content, xmlArr[index].content) == 0 )
        {
            //MyPrintf("List index[%d] str [%s] matched.", index, strArr[index]);
            index++;
            ptCurNode = ptCurNode->next;
        }
        else
        {
            StopWithMsg("List index xml don't matched.");
            return;
        }
    }
   
    if ( xmlArr[index].tagName != NULL )
    {
        StopWithMsg("AssertList failed.");
        return;
    }
    else
    {
        //MyPrintf("match all");
    }
}

void TestList()
{
    T_NODE headNode = {NULL, NULL};
   
    Insert2List(&headNode, "first", "firstcontent");
    Insert2List(&headNode, "second", "secondcontent");
   
    PrintList(&headNode);
   
    T_XML_NODE xmlArr[] = {
        {"second", "secondcontent"},
        {"first", "firstcontent"},
        {NULL, NULL},
    };
    AssertList(&headNode, xmlArr);
    
    FreeList(&headNode);
}

// list 链表操作测试用例
void TestListCase()
{
    TestList();
}

/* ------------------------------ 普通字符串 -------------------------------- */
#define STRING_MEM_BACK_SIZE 516 // 字符串预留空间，以备后续添加字符

// 初始化字符串对象
void InitStrObjStruct(PT_STRING_OBJ ptStrObj, char* szStr, E_BOOL_TYPE bIsMalloc)
{
    ptStrObj->iLen = strlen(szStr);
    ptStrObj->iIndex = 0;
    ptStrObj->bIsMalloc = bIsMalloc;
    
    if ( bIsMalloc )
    {
        ptStrObj->iMallocSize = ptStrObj->iLen+STRING_MEM_BACK_SIZE;
        ptStrObj->szStr = malloc(ptStrObj->iMallocSize);
        strncpy(ptStrObj->szStr, szStr, ptStrObj->iLen);
        ptStrObj->szStr[ptStrObj->iLen] = '\0';
    }
    else
    {
        ptStrObj->szStr = szStr;
    }
}

void AddChar2StrObj(PT_STRING_OBJ ptStrObj, char cChar)
{
    if ( !ptStrObj->bIsMalloc )
    {
        return ;
    }

    if ( ptStrObj->iLen >= ptStrObj->iMallocSize-1 )
    {
        ptStrObj->szStr = realloc(ptStrObj->szStr, ptStrObj->iMallocSize+STRING_MEM_BACK_SIZE);
        if ( !ptStrObj->szStr )
        {
            StopWithMsg("realloc fail");
            return;
        }
        else
        {
            ptStrObj->iMallocSize = ptStrObj->iMallocSize+STRING_MEM_BACK_SIZE;
        }
    }
    
    ptStrObj->szStr[ptStrObj->iLen] = cChar;
    ptStrObj->iLen++;
    ptStrObj->szStr[ptStrObj->iLen] = '\0';
}

void FreeStrObjMem(PT_STRING_OBJ ptStrObj)
{
    if ( ptStrObj->bIsMalloc )
    {
        FreeStrPoint(&(ptStrObj->szStr));
    }
}

// 从字符串中获取当前一个字符，并将指针指向下一个字符
char GetCharFromStr(PT_STRING_OBJ ptStrObj)
{
    char retChar = '\0';
    
    if ( ptStrObj->iIndex >= ptStrObj->iLen )
    {
        // 已到尾部，无字符串可取
        return '\0';
    }
    
    // get current char
    retChar = ptStrObj->szStr[ptStrObj->iIndex];
    
    // navigate to next char
    ptStrObj->iIndex++;
    
    return retChar;
}

// 从字符串中获取当前一个字符，不执行指针指向下一个字符
char GetCharFromStr_purely(PT_STRING_OBJ ptStrObj)
{
    char retChar = '\0';
    
    if ( ptStrObj->iIndex >= ptStrObj->iLen )
    {
        // 已到尾部，无字符串可取
        return '\0';
    }
    
    // get current char
    retChar = ptStrObj->szStr[ptStrObj->iIndex];
    
    return retChar;
}

//比较字符， 迁移str的index
E_BOOL_TYPE MatchCharInStr(char cChar, PT_STRING_OBJ ptStrObj)
{
    char cCurChar = GetCharFromStr(ptStrObj);
    if ( cCurChar == '\0' )
    {
        return FALSE;
    }
    
    if ( cChar == cCurChar )
    {
        return TRUE;
    }
    
    return FALSE;
}

//只比较字符， 不迁移str的index
E_BOOL_TYPE MatchCharInStr_purely(char cChar, PT_STRING_OBJ ptStrObj)
{
    char cCurChar = GetCharFromStr_purely(ptStrObj);
    if ( cCurChar == '\0' )
    {
        return FALSE;
    }
    
    if ( cChar == cCurChar )
    {
        return TRUE;
    }
    
    return FALSE;
}

//比较Optional字符， 比较成功迁移str的index
E_BOOL_TYPE MatchOptCharsInStr(char* szOptChars, PT_STRING_OBJ ptStrObj)
{
    char cCurChar = GetCharFromStr_purely(ptStrObj);
    if ( cCurChar == '\0' )
    {
        return FALSE;
    }

    // 字符串中含有字符
    if ( strchr(szOptChars, cCurChar) )
    {
        ptStrObj->iIndex++;
        return TRUE;
    }
    
    return FALSE;
}

/* ------------------------------ single layer xml parsing --------------------------------- */

// current is state null, begintag state can be triggered? 
E_BOOL_TYPE IsEventTriggered_StateNull_Jump2StartTag(char cCurrentChar)
{
    if ( '<' == cCurrentChar )
    {
        return TRUE;
    }    
    
    return FALSE;
}

// current is state null, begintag event is triggered, now do some action
E_RETURN_TYPE EventHandler_StateNull_Jump2StartTag(char cCurrentChar, PT_XML_PARSE_STATE_MACHINE ptStateMachine, PT_NODE ptHead)
{
    // discard current char, do not revise state machine
}

// current is state null, begintag state can not be triggered? 
E_BOOL_TYPE IsEventTriggered_StateNull_KeepState(char cCurrentChar)
{
    if ( '<' != cCurrentChar )
    {
        return TRUE;
    }    
    
    return FALSE;
}

// current is state null, begintag event is not triggered, now do some action
E_RETURN_TYPE EventHandler_StateNull_KeepState(char cCurrentChar, PT_XML_PARSE_STATE_MACHINE ptStateMachine, PT_NODE ptHead)
{
    // discard current char, do not revise state machine
}

// current is state start tag, can the event jumps to Content state be triggered? 
E_BOOL_TYPE IsEventTriggered_StateStartTag_Jump2Content(char cCurrentChar)
{
    if ( '>' == cCurrentChar )
    {
        return TRUE;
    }    
    
    return FALSE;
}

// current is state starttag, jump2Content event is triggered, now do some action
E_RETURN_TYPE EventHandler_StateStartTag_Jump2Content(char cCurrentChar, PT_XML_PARSE_STATE_MACHINE ptStateMachine, PT_NODE ptHead)
{
    // discard current char, do not revise state machine
}

// current is state start tag, can the event keeps this state be triggered? 
E_BOOL_TYPE IsEventTriggered_StateStartTag_KeepState(char cCurrentChar)
{
    if ( '>' != cCurrentChar )
    {
        return TRUE;
    }    
    
    return FALSE;
}

// current is state starttag, keepState event is triggered, now do some action
E_RETURN_TYPE EventHandler_StateStartTag_KeepState(char cCurrentChar, PT_XML_PARSE_STATE_MACHINE ptStateMachine, PT_NODE ptHead)
{
    // save current char to state machine
    AddChar2StrObj(&ptStateMachine->tStartTag, cCurrentChar);
}

// current is state start tag, can the event jumps to Content state be triggered? 
E_BOOL_TYPE IsEventTriggered_StateContent_Jump2EndTag(char cCurrentChar)
{
    if ( '<' == cCurrentChar )
    {
        return TRUE;
    }    
    
    return FALSE;
}

// current is state starttag, jump2Content event is triggered, now do some action
E_RETURN_TYPE EventHandler_StateContent_Jump2EndTag(char cCurrentChar, PT_XML_PARSE_STATE_MACHINE ptStateMachine, PT_NODE ptHead)
{
    // discard current char, do not revise state machine
}

// current is state start tag, can the event keeps this state be triggered? 
E_BOOL_TYPE IsEventTriggered_StateContent_KeepState(char cCurrentChar)
{
    if ( '<' != cCurrentChar )
    {
        return TRUE;
    }    
    
    return FALSE;
}

// current is state starttag, keepState event is triggered, now do some action
E_RETURN_TYPE EventHandler_StateContent_KeepState(char cCurrentChar, PT_XML_PARSE_STATE_MACHINE ptStateMachine, PT_NODE ptHead)
{
    // save current char to state machine
    AddChar2StrObj(&ptStateMachine->tContent, cCurrentChar);
}

// current is state start tag, can the event jumps to Content state be triggered? 
E_BOOL_TYPE IsEventTriggered_StateEndTag_Jump2Null(char cCurrentChar)
{
    if ( '>' == cCurrentChar )
    {
        return TRUE;
    }    
    
    return FALSE;
}

// current is state starttag, jump2Content event is triggered, now do some action
E_RETURN_TYPE EventHandler_StateEndTag_Jump2Null(char cCurrentChar, PT_XML_PARSE_STATE_MACHINE ptStateMachine, PT_NODE ptHead)
{
MyPrintf("EventHandler_StateEndTag_Jump2Null enter");
    // discard current char, compare starttag with endtag
    // if starttag equals to endtag, add tagName-content into list
    if ( !strcmp(ptStateMachine->tStartTag.szStr, ptStateMachine->tEndTag.szStr) )
    {
        Insert2List(ptHead, ptStateMachine->tStartTag.szStr, ptStateMachine->tContent.szStr);
    }
    else
    {
        MyPrintf("start tag(%s) do not match end tag(%s), ", ptStateMachine->tStartTag.szStr, ptStateMachine->tEndTag.szStr);
    }

    FreeXMLParseStateMachine(ptStateMachine);
    InitXMLParseStateMachine(ptStateMachine);
}

// current is state start tag, can the event keeps this state be triggered? 
E_BOOL_TYPE IsEventTriggered_StateEndTag_KeepState(char cCurrentChar)
{
    if ( '>' != cCurrentChar )
    {
        return TRUE;
    }    
    
    return FALSE;
}

// current is state starttag, keepState event is triggered, now do some action
E_RETURN_TYPE EventHandler_StateEndTag_KeepState(char cCurrentChar, PT_XML_PARSE_STATE_MACHINE ptStateMachine, PT_NODE ptHead)
{
    // save current char to state machine
    AddChar2StrObj(&ptStateMachine->tEndTag, cCurrentChar);
}

void InitXMLParseStateMachine(PT_XML_PARSE_STATE_MACHINE ptXMLParseStateMachine)
{
    ptXMLParseStateMachine->eParseState = XML_PARSE_STATE_NULL;

    InitStrObjStruct(&(ptXMLParseStateMachine->tStartTag), "", TRUE);
    InitStrObjStruct(&(ptXMLParseStateMachine->tEndTag), "", TRUE);
    InitStrObjStruct(&(ptXMLParseStateMachine->tContent), "", TRUE);
}

void FreeXMLParseStateMachine(PT_XML_PARSE_STATE_MACHINE ptXMLParseStateMachine)
{
    FreeStrObjMem(&(ptXMLParseStateMachine->tStartTag));
    FreeStrObjMem(&(ptXMLParseStateMachine->tEndTag));
    FreeStrObjMem(&(ptXMLParseStateMachine->tContent));
}

int GetStateChangeRuleIndex(E_XML_PARSE_STATE eState, char cCurrentChar)
{
    int iIndex = 0;
    int iLen = sizeof(g_stateChangeTable)/sizeof(T_STATE_CHANGE_RULE); 
    
    for ( iIndex=0; iIndex<iLen; iIndex++ )
    {
        if ( eState == g_stateChangeTable[iIndex].eCurrentState )
        {
            if ( g_stateChangeTable[iIndex].isEventTriggered(cCurrentChar) )
            {
                return iIndex;
            }
        }
    }
    
    return -1;
} 

// main function for xml parsing
void ParseXMLStr(char* szXMLStr, PT_NODE ptHead)
{
    T_STRING_OBJ tXmlStr;
    T_XML_PARSE_STATE_MACHINE tXmlMachine;
    PT_XML_PARSE_STATE_MACHINE ptXmlMachine = &tXmlMachine;
    int iIndex = 0;
    char cChar = '\0';
    
    InitStrObjStruct(&tXmlStr, szXMLStr, FALSE);
    InitXMLParseStateMachine(&tXmlMachine);
    
    while( (cChar = GetCharFromStr(&tXmlStr)) )
    {
        MyPrintf("current eParseState = %d", ptXmlMachine->eParseState);
        MyPrintf("input char = %c", cChar);
        
        iIndex = GetStateChangeRuleIndex(ptXmlMachine->eParseState, cChar);
        MyPrintf("machine rule iIndex=%d", iIndex);
        if ( -1 != iIndex )
        {
            ptXmlMachine->eParseState = g_stateChangeTable[iIndex].eTransferState;
            MyPrintf("changed eParseState = %d\n", ptXmlMachine->eParseState);
            
            g_stateChangeTable[iIndex].eventhandler(cChar, ptXmlMachine, ptHead);
        }
        else
        {
            StopWithMsg("state machine run encounter error!");
        }
    }

    FreeXMLParseStateMachine(ptXmlMachine);
}

// test xml parsing result
void TestXMLPasring(char* szXMLStr, T_XML_NODE xmlArr[])
{
    T_NODE tHead = {
        NULL,
        NULL,
        NULL
    };
    
    ParseXMLStr(szXMLStr, &tHead);

    PrintList(&tHead);
    
    AssertList(&tHead, xmlArr);
    
    MyPrintf("szXMLStr(%s) test ok!-----------------\n\n", szXMLStr);
}

void TestXMLParseCase()
{
    // test one node postive case
    T_XML_NODE xmlArr[] = {
        {
            "xx",
            "yy"
        },
        {
            NULL,
            NULL
        }
    };
    TestXMLPasring("<xx>yy<xx>", xmlArr);
    
    // test one node negative case
    T_XML_NODE xmlArr1[] = {
        {
            NULL,
            NULL
        }
    };
    TestXMLPasring("<xx>yy<KKxx>", xmlArr1);
    
}

int main(){
    //TestListCase();
    
    TestXMLParseCase();
    
    return 0;
}

