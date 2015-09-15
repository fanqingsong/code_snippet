#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>
#include <stdarg.h>


/* ------------------------------ 声明区域 --------------------------------- */

// list node
typedef struct node{
    char* str;
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

// pattern modifier : {} * +
typedef enum ModifierType{
    MODIFIER_TYPE_PLAIN, // PLAIN CHAR
    MODIFIER_TYPE_FIXCOUNT, // {X}
    MODIFIER_TYPE_ZEROPLUS, // *
    MODIFIER_TYPE_ONEPLUS, // +
    MODIFIER_TYPE_QUESTIONMARK, // ?
} E_MODIFIER_TYPE;

typedef struct patternChar{
    char cChar;
    E_MODIFIER_TYPE modifyType;
    int modifyPara;
} T_PAT_CHAR, *PT_PAT_CHAR;

typedef struct stringObj{
    char* szStr;
    int iLen;
    int iIndex;
} T_STRING_OBJ, *PT_STRING_OBJ;

typedef E_BOOL_TYPE (*MatchModifier)(PT_STRING_OBJ, PT_PAT_CHAR);
typedef E_BOOL_TYPE (*MatchStrByModifier)(PT_PAT_CHAR, PT_STRING_OBJ);

typedef struct PatCharModifier{
    E_MODIFIER_TYPE modifyType;
    MatchModifier matchModifier;
    MatchStrByModifier matchStrByModifier;
} T_PATCHAR_MODIFIER, PT_PATCHAR_MODIFIER;


void MyPrintf(char* fmt, ...);
char* DupSubStr(char* str, int start, int end);
void StopWithMsg(char* msg);

E_BOOL_TYPE MatchFixCount(PT_STRING_OBJ ptPatObj, PT_PAT_CHAR ptPatChar);
E_BOOL_TYPE MatchStrByFixCount(PT_PAT_CHAR ptPatChar, PT_STRING_OBJ ptStrObj);

E_BOOL_TYPE MatchQuestionMark(PT_STRING_OBJ ptPatObj, PT_PAT_CHAR ptPatChar);
E_BOOL_TYPE MatchStrByQuestionMark(PT_PAT_CHAR ptPatChar, PT_STRING_OBJ ptStrObj);

E_BOOL_TYPE MatchZeroPlus(PT_STRING_OBJ ptPatObj, PT_PAT_CHAR ptPatChar);
E_BOOL_TYPE MatchStrByZeroPlus(PT_PAT_CHAR ptPatChar, PT_STRING_OBJ ptStrObj);

E_BOOL_TYPE MatchOnePlus(PT_STRING_OBJ ptPatObj, PT_PAT_CHAR ptPatChar);
E_BOOL_TYPE MatchStrByOnePlus(PT_PAT_CHAR ptPatChar, PT_STRING_OBJ ptStrObj);

E_BOOL_TYPE MatchPlain(PT_STRING_OBJ ptPatObj, PT_PAT_CHAR ptPatChar);
E_BOOL_TYPE MatchStrByPlain(PT_PAT_CHAR ptPatChar, PT_STRING_OBJ ptStrObj);


/* ------------------------------ 全局变量 --------------------------------- */
T_PATCHAR_MODIFIER g_patCharModifier[] = {
    {MODIFIER_TYPE_FIXCOUNT, MatchFixCount, MatchStrByFixCount},
    {MODIFIER_TYPE_QUESTIONMARK, MatchQuestionMark, MatchStrByQuestionMark},
    {MODIFIER_TYPE_ZEROPLUS, MatchZeroPlus, MatchStrByZeroPlus},
    {MODIFIER_TYPE_ONEPLUS, MatchOnePlus, MatchStrByOnePlus},
    
    // plain 必须放在最后， 以满足， 其他修饰符都未匹配，默认使用此匹配符号
    {MODIFIER_TYPE_PLAIN,    MatchPlain,    MatchStrByPlain},
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

void StopWithMsg(char* msg)
{
    puts(msg);
    assert(0);
}

/* ------------------------------ 链表函数 --------------------------------- */
void FreeList(PT_NODE ptHeadNode)
{
    PT_NODE ptCurNode = ptHeadNode->next;
    PT_NODE ptNextNode = NULL;
    while(ptCurNode)
    {
        ptNextNode = ptCurNode->next;
        if ( ptCurNode->str != NULL )
        {
            free(ptCurNode->str);
        }
        free(ptCurNode);
        ptCurNode = ptNextNode;
    }
}

int Insert2List(PT_NODE ptHeadNode, char* str)
{
    PT_NODE ptNode = NULL;
    PT_NODE ptFirst = NULL;
   
    //MyPrintf("Insert2List str is %s", str);
   
    ptNode = (PT_NODE) malloc(sizeof(T_NODE));
    if ( ptNode == NULL )
    {
        return -1;
    }
   
    ptNode->str = str;
   
    ptFirst = ptHeadNode->next;
    ptHeadNode->next = ptNode;
    ptNode->next = ptFirst;
}

void PrintList(PT_NODE ptHeadNode)
{
    PT_NODE ptCurNode = NULL;
    MyPrintf("---- list printing begin -----");
 
     ptCurNode = ptHeadNode->next;
    while(ptCurNode)
    {
        MyPrintf("node str is %s", ptCurNode->str);
        ptCurNode = ptCurNode->next;
    }
   
    MyPrintf("---- list printing end -----");
}

void AssertList(PT_NODE ptHeadNode, char* strArr[]){
    int index = 0;
    PT_NODE ptCurNode = ptHeadNode->next;
   
    while(ptCurNode)
    {
        if ( strArr[index] == NULL )
        {
            StopWithMsg("strArr reach top, but list not over.");
            return;
        }
       
        if ( strcmp(ptCurNode->str, strArr[index]) == 0 )
        {
            //MyPrintf("List index[%d] str [%s] matched.", index, strArr[index]);
            index++;
            ptCurNode = ptCurNode->next;
        }
        else
        {
            StopWithMsg("List index str don't matched.");
            return;
        }
    }
   
    if ( strArr[index] != NULL )
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
   
    Insert2List(&headNode, "first");
    Insert2List(&headNode, "second");
   
    PrintList(&headNode);
   
    char* strArr[] = {
        "second",
        "first",
        NULL
    };
    AssertList(&headNode, strArr);
    FreeList(&headNode);
}

// list 链表操作测试用例
void TestListCase()
{
    TestList();
}

/* ------------------------------ 普通字符串 -------------------------------- */
// 初始化字符串对象
void InitStrObjStruct(PT_STRING_OBJ ptStrObj)
{
    ptStrObj->iLen = strlen(ptStrObj->szStr);
    ptStrObj->iIndex = 0;
}

// 从字符串中获取下一个字符
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

/* ------------------------------ 模式匹配 --------------------------------- */
// from pattern begining, match {xx}, xx is digits [1234567890]
int MatchCurlyBracket(char* str, int* piFixCount)
{
    int span = 0;
    
    if ( !str )
    {
        return 0;
    }
    
    if ( str[0] != '{' )
    {
        return 0;
    }
    
    // count { len
    span++;
    
    int count = strspn(str+span, "1234567890");
    //MyPrintf("MatchCurlyBracket count=%d", count);
    if ( count == 0 )
    {
        return 0;
    }
    
    //count xx length, xx in {xx}
    span += count;
    
    if ( str[span] != '}' )
    {
        return 0;
    }
    
    // count } len
    span++;
    
    char* sTemp = DupSubStr(str+1, 0, count-1);
    if ( sTemp == NULL )
    {
        return 0;
    }
    
    *piFixCount = atoi(sTemp);
    free(sTemp);
    sTemp = NULL;
    
    return span;
}

// if match fixcount modifier, then renew patObj, and record to patChar
E_BOOL_TYPE MatchFixCount(PT_STRING_OBJ ptPatObj, PT_PAT_CHAR ptPatChar)
{
    int fixCount = 0;
    int span = 0;
    
    span = MatchCurlyBracket(ptPatObj->szStr+ptPatObj->iIndex, &fixCount);
    
    //MyPrintf("GetPatCharFromPattern MatchCurlyBracket=%d", span);
    if ( span > 0 )
    {
        ptPatObj->iIndex += span;
        
        ptPatChar->modifyType = MODIFIER_TYPE_FIXCOUNT;
        ptPatChar->modifyPara = fixCount;
        
        return TRUE;
    }
    
    return FALSE;
}

E_BOOL_TYPE MatchStrByFixCount(PT_PAT_CHAR ptPatChar, PT_STRING_OBJ ptStrObj)
{
    int fixCount = ptPatChar->modifyPara;
    char cChar = ptPatChar->cChar;
    
    int index = 0;
    for ( index=0; index<fixCount; index++ )
    {
        if ( !MatchCharInStr(cChar, ptStrObj) )
        {
            return FALSE;
        }
    }
    
    return TRUE;
}

E_BOOL_TYPE MatchQuestionMark(PT_STRING_OBJ ptPatObj, PT_PAT_CHAR ptPatChar)
{
    if ( '?' == ptPatObj->szStr[ptPatObj->iIndex] )
    {
        ptPatObj->iIndex++;
        
        ptPatChar->modifyType = MODIFIER_TYPE_QUESTIONMARK;
        
        return TRUE;
    }
    
    return FALSE;
}

E_BOOL_TYPE MatchStrByQuestionMark(PT_PAT_CHAR ptPatChar, PT_STRING_OBJ ptStrObj)
{
    char cChar = ptPatChar->cChar;

    char szChar[2] = {0};
    szChar[0] = cChar;
    
    // 1? 先按照 1 来匹配
    int span = strspn(ptStrObj->szStr+ptStrObj->iIndex, szChar);
    if ( span >= 1 )
    {
        // 迁移一位
        ptStrObj->iIndex++;
        return TRUE;
    }
    
    // 1? 先按照 空 来匹配， 不迁移index
    return TRUE;
}

E_BOOL_TYPE MatchZeroPlus(PT_STRING_OBJ ptPatObj, PT_PAT_CHAR ptPatChar)
{
    if ( '*' == ptPatObj->szStr[ptPatObj->iIndex] )
    {
        ptPatObj->iIndex++;
        
        ptPatChar->modifyType = MODIFIER_TYPE_ZEROPLUS;
        
        return TRUE;
    }
    
    return FALSE;
}

E_BOOL_TYPE MatchStrByZeroPlus(PT_PAT_CHAR ptPatChar, PT_STRING_OBJ ptStrObj)
{
    char cChar = ptPatChar->cChar;

    char szChar[2] = {0};
    szChar[0] = cChar;
    
    // 贪婪匹配
    int span = strspn(ptStrObj->szStr+ptStrObj->iIndex, szChar);
    if ( span >= 1 )
    {
        // index迁移到不是 cChar 的字符
        ptStrObj->iIndex += span;
        return TRUE;
    }
    
    // zeroplus（*） 允许空匹配， 不迁移index
    return TRUE;
}

E_BOOL_TYPE MatchOnePlus(PT_STRING_OBJ ptPatObj, PT_PAT_CHAR ptPatChar)
{
    if ( '+' == ptPatObj->szStr[ptPatObj->iIndex] )
    {
        ptPatObj->iIndex++;
        
        ptPatChar->modifyType = MODIFIER_TYPE_ONEPLUS;
        
        return TRUE;
    }
    
    return FALSE;
}

E_BOOL_TYPE MatchStrByOnePlus(PT_PAT_CHAR ptPatChar, PT_STRING_OBJ ptStrObj)
{
    char cChar = ptPatChar->cChar;

    char szChar[2] = {0};
    szChar[0] = cChar;
    
    // 贪婪匹配
    int span = strspn(ptStrObj->szStr+ptStrObj->iIndex, szChar);
    if ( span >= 1 )
    {
        // index迁移到不是 cChar 的字符
        ptStrObj->iIndex += span;
        return TRUE;
    }
    
    // oneplus（+） 不允许空匹配
    return FALSE;
}

E_BOOL_TYPE MatchPlain(PT_STRING_OBJ ptPatObj, PT_PAT_CHAR ptPatChar)
{
    ptPatChar->modifyType = MODIFIER_TYPE_PLAIN;
    
    //作为普通字符，默认匹配通过
    return TRUE;
}

E_BOOL_TYPE MatchStrByPlain(PT_PAT_CHAR ptPatChar, PT_STRING_OBJ ptStrObj)
{
    char cChar = ptPatChar->cChar;

    if ( !MatchCharInStr(cChar, ptStrObj) )
    {
        return FALSE;
    }
    
    return TRUE;
}

// 从模式字符串中获取下一个模式字符
E_RETURN_TYPE GetPatCharFromPattern(PT_PAT_CHAR ptPatChar, PT_STRING_OBJ ptPatObj)
{
    char cChar = GetCharFromStr(ptPatObj);
    if ( cChar == '\0' )
    {
        // pattern char exhausted
        return FAIL;
    }
    
    ptPatChar->cChar = cChar;
    //MyPrintf("GetPatCharFromPattern cChar=%c", cChar);
    
    //获取模式字符的 修饰符 例如 {xx}
    int len = sizeof(g_patCharModifier)/sizeof(T_PATCHAR_MODIFIER);
    int index = 0;
    E_BOOL_TYPE bMatched = FALSE;
    for ( index=0; index<len; index++ )
    {
        bMatched = g_patCharModifier[index].matchModifier(ptPatObj, ptPatChar);
        if ( bMatched == TRUE )
        {
            break;
        }
    }
    
    return SUCCESS;
}

// 从字符串开始位置 ，匹配模式字符 pattern char
E_BOOL_TYPE MatchPatChar(PT_PAT_CHAR ptPatChar, PT_STRING_OBJ ptStrObj)
{
    if( !ptPatChar || !ptStrObj )
    {
        return FALSE;
    }
    
    int len = sizeof(g_patCharModifier)/sizeof(T_PATCHAR_MODIFIER);
    int index = 0;
    E_BOOL_TYPE bMatched = FALSE;
    E_MODIFIER_TYPE eModType = MODIFIER_TYPE_PLAIN;
    
    for ( index=0; index<len; index++ )
    {
        eModType = g_patCharModifier[index].modifyType;
        
        if ( eModType == ptPatChar->modifyType )
        {
            bMatched = g_patCharModifier[index].matchStrByModifier(ptPatChar, ptStrObj);
            break;
        }
    }
    
    return bMatched;
}
 
void GetMatchedList(PT_NODE ptHeadNode, char* pattern, char* str)
{ 
    T_STRING_OBJ tPatObj;
    T_STRING_OBJ tStrObj;
    T_PAT_CHAR tPatChar;
    
    if ( !pattern || !str )
    {
        StopWithMsg("GetMatedList argument null");
    }
    
    memset(&tPatObj, 0, sizeof(T_STRING_OBJ));
    memset(&tStrObj, 0, sizeof(T_STRING_OBJ));
    memset(&tPatChar, 0, sizeof(T_PAT_CHAR));
    
    tPatObj.szStr = pattern;
    tStrObj.szStr = str;
    
    InitStrObjStruct(&tPatObj);
    InitStrObjStruct(&tStrObj);
    
    E_BOOL_TYPE bAllPatCharMatched = TRUE;
    
    MyPrintf("pattern =%s", tPatObj.szStr);
    while( GetPatCharFromPattern(&tPatChar, &tPatObj) )
    {
        if ( !MatchPatChar(&tPatChar, &tStrObj) )
        {
            MyPrintf("pattern char=%c match fail", tPatChar.cChar);
            bAllPatCharMatched = FALSE;
            break;
        }
        
        MyPrintf("pattern char=%c match success", tPatChar.cChar);
    }
    
    char* szMatchStr = NULL;
    if ( bAllPatCharMatched )
    {
        szMatchStr = DupSubStr(tStrObj.szStr, 0, tStrObj.iIndex-1);
        Insert2List(ptHeadNode, szMatchStr);
    }
    
    // stub code
    //Insert2List(ptHeadNode, "35");
}

void TestPattern(char* pattern, char* str, char* strArr[])
{
    T_NODE tHeadNode = {
        NULL,
        NULL
    };
   
    MyPrintf("<<-- pattern[%s] apply to str[%s] want [%s] BEGIN!", pattern, str, strArr[0]);
   
    GetMatchedList(&tHeadNode, pattern, str);
   
    PrintList(&tHeadNode);
   
    AssertList(&tHeadNode, strArr);
   
    MyPrintf("-->> pattern[%s] apply to str[%s] want [%s] OK!\n", pattern, str, strArr[0]);
   
    FreeList(&tHeadNode);
}

/* 测试用例：
Pattern     string          result
"35"        "354"           "35"
"3{2}5"     "3354"          "335"
"3{4}"      "3334"          null
"1*"        "11123"         "","1","11","111" -- 按照贪婪策略匹配 
"1?"        "11123"         "","1"   --- 两个结果理解上拆分为二个测试用例 ，见下面  test ? question mark
"1|2|3"     "123"           "1"
"[12]+"     "1123"          "1", "11", "112"
*/
void TestPatternCase()
{
    // test plain
    char* strArr[] = {"35", NULL};
    TestPattern("35", "354", strArr);
   
    // test {} sign positive case
    char* strArr1[] = {"335", NULL};
    TestPattern("3{2}5", "3354", strArr1);
    
    // test {} sign negative case
    char* strArr2[] = {NULL};
    TestPattern("3{4}", "3334", strArr2);
    
    // test ? question mark - match one
    char* strArr3[] = {"1", NULL};
    TestPattern("1?", "11123", strArr3);

    // test ? question mark - match none    
    char* strArr4[] = {"", NULL};
    TestPattern("1?", "21123", strArr4);
    
    // test asterisk 
	//"1*"        "11123"         "","1","11","111" -- 贪婪匹配一个最长值 
    char* strArr5[] = {"111", NULL};
    TestPattern("1*", "11123", strArr5);
    
    // test asterisk 
	//"1+"        "11123"         "","1","11","111"  -- 贪婪匹配一个最长值 
    char* strArr6[] = {"111", NULL};
    TestPattern("1+", "11123", strArr6);
}

int main(void)
{
    // test list function
    //TestListCase();
   
    // test pattern case
    TestPatternCase();
   
    return 0;
}


