
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>
#include <stdarg.h>
#include <ctype.h>


/* ------------------------------ declaration area  --------------------------------- */

// list node
typedef struct ListLinkNode{
    struct ListLinkNode* prev;
    struct ListLinkNode* next;
} T_LIST_LINKNODE, *PT_LIST_LINKNODE;

// initialize the head and tail of list head as self
#define INIT_LIST_HEAD(ptListHead) do { \
                        (ptListHead)->next = (ptListHead);\
                        (ptListHead)->prev = (ptListHead); \
                        } while (0)

// insert new link node between previous link node and next link node
// note: if clause is must item to add node to empty list, otherwise list_add_tail error
#define _list_add(newLink, prevLink, nextLink) do{\
                        (newLink)->next = (nextLink);\
                        (newLink)->prev = (prevLink);\
                        if ( (prevLink) == (nextLink) ){\
                            (prevLink)->next = (newLink);\
                            (prevLink)->prev = (newLink);\
                        }else{\
                            (prevLink)->next = (newLink);\
                            (nextLink)->prev = (newLink);\
                        }\
                        } while(0)

// delete the specific link node from list
#define list_del(ptLinkNode) do{\
                        (ptLinkNode)->prev->next = (ptLinkNode)->next;\
                        (ptLinkNode)->next->prev = (ptLinkNode)->prev;\
                        (ptLinkNode)->prev = NULL;\
                        (ptLinkNode)->next = NULL;\
                        } while(0)

// add new list node to  list head
#define list_add_head(ptListHead, ptListNewLink) do {\
                        _list_add((ptListNewLink), (ptListHead), (ptListHead)->next);\
                        } while(0)

// add new list node to  list tail
#define list_add_tail(ptListHead, ptListNewLink) do {\
                        _list_add((ptListNewLink), ((ptListHead)->prev), (ptListHead));\
                        } while(0)

// list for each
#define list_for_each(ptListHead, ptLinkNode) \
                        (ptLinkNode) = (ptListHead)->next;\
                        for(;(ptLinkNode) != (ptListHead); (ptLinkNode)=(ptLinkNode)->next)

// list for each safe -- prevent breaking list after call list_del
#define list_for_each_safe(ptListHead, ptLinkNode, ptNextCache) \
                        (ptLinkNode) = (ptListHead)->next;\
                        for(;(ptNextCache)=(ptLinkNode)->next, (ptLinkNode) != (ptListHead); (ptLinkNode)=(ptNextCache) )

//get list entry
// ptLinkNode -- the link node pointer of one structure
// StructType -- definition name of the structure that link node is in
// LinkNodeMember -- the link node member name in StructType
#define list_entry(ptLinkNode, StructType, LinkNodeMember)\
                        (StructType*)((void*)(ptLinkNode) - (void*)(&((StructType*)0)->LinkNodeMember))

typedef struct node{
    T_LIST_LINKNODE tLinkNode;
    char* str; // record operation element (string type), including operand 1, operator +, bracket  ( 
    int number; // translate number string to int, and save operand to this
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


/* ------------------------------ common function --------------------------------- */

// printf function format arguments
#define MyVaPrintf(fmt)\
                va_list args;\
                va_start(args, fmt);\
                vprintf(fmt, args);\
                va_end(args);\
                printf("\r\n");

// MyPrintf == puts + format args
void MyPrintf(char* fmt, ...)
{
    MyVaPrintf(fmt);
}

// copy specific slice of string to a new string memory
char* DupSubStr(char* str, int start, int end)
{
    char* newStr = NULL;
   
    // sub string len 
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

void StopWithMsg(char* fmt, ...)
{
    //puts(msg);
    MyVaPrintf(fmt);
    assert(0);
}

void MyAssert(E_BOOL_TYPE bConditionExp, char* fmt, ...)
{
    if ( !bConditionExp )
    {
        MyVaPrintf(fmt);
        assert(0);
    }
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


/***********************************************************************
                                LIST fundemental function
************************************************************************/
E_BOOL_TYPE IsListEmpty(PT_LIST_LINKNODE ptListHead)
{
    if (ptListHead->next == ptListHead)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void FreeListNode(PT_NODE ptNode)
{
    if ( !ptNode )
    {
         return;
    }

    if ( ptNode->str != NULL )
    {
        free(ptNode->str);
        ptNode->str = NULL;
    }
    
    free(ptNode);        
}

void FreeList(PT_LIST_LINKNODE ptListHead)
{
    PT_NODE ptCurNode = NULL;
    PT_LIST_LINKNODE ptNextNode = NULL;
    PT_LIST_LINKNODE ptLinkNode =  NULL;

    list_for_each_safe(ptListHead, ptLinkNode, ptNextNode){
        ptCurNode = list_entry(ptLinkNode, T_NODE, tLinkNode);

        list_del(&(ptCurNode->tLinkNode));

        FreeListNode(ptCurNode);
        ptCurNode = NULL;
    }
}

PT_NODE List_DetachFirstNode(PT_LIST_LINKNODE ptListHead)
{
    PT_NODE ptNode = NULL;
    PT_LIST_LINKNODE ptLinkNode = NULL;

    if ( IsListEmpty(ptListHead) )
    {
        return NULL;
    }

    ptLinkNode = ptListHead->next;
    list_del(ptLinkNode);

    ptNode = list_entry(ptLinkNode, T_NODE, tLinkNode);

    return ptNode;
}

PT_NODE List_DetachLastNode(PT_LIST_LINKNODE ptListHead)
{
    PT_LIST_LINKNODE ptLinkNode = NULL;
    PT_NODE ptNode = NULL;
    
    if ( IsListEmpty(ptListHead) )
    {
        return NULL;
    }
    
    ptLinkNode = ptListHead->prev;
    list_del(ptLinkNode);
    
    ptNode = list_entry(ptLinkNode, T_NODE, tLinkNode);
    
    return ptNode;
}

void List_AddNode2Head(PT_LIST_LINKNODE ptListHead, PT_NODE ptNode)
{
    list_add_head(ptListHead, &(ptNode->tLinkNode));
}

void List_AddNode2Tail(PT_LIST_LINKNODE ptListHead, PT_NODE ptNode)
{
    list_add_tail(ptListHead, &(ptNode->tLinkNode));
}

//create a node with string str and insert node into list
int InsertStr2ListHead(PT_LIST_LINKNODE ptListHead, char* str)
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

   list_add_head(ptListHead, &(ptNode->tLinkNode));
}

void PrintList(PT_LIST_LINKNODE ptListHead)
{
    PT_NODE ptCurNode = NULL;
    PT_LIST_LINKNODE ptLinkNode =  NULL;
    
    MyPrintf("---- list printing begin -----");

    list_for_each(ptListHead, ptLinkNode){
        ptCurNode = list_entry(ptLinkNode, T_NODE, tLinkNode);
        
        MyPrintf("node str is %s", ptCurNode->str);        
    }
   
    MyPrintf("---- list printing end -----");
}

void AssertList(PT_LIST_LINKNODE ptListHead, char* strArr[]){
    int index = 0;
    PT_NODE ptCurNode = NULL;
    PT_LIST_LINKNODE ptLinkNode =  NULL;
    
    list_for_each(ptListHead, ptLinkNode){
        ptCurNode = list_entry(ptLinkNode, T_NODE, tLinkNode);
        
        if ( strArr[index] == NULL )
        {
            StopWithMsg("strArr reach top, but list not over.");
            return;
        }
       
        if ( strcmp(ptCurNode->str, strArr[index]) == 0 )
        {
            //MyPrintf("List index[%d] str [%s] matched.", index, strArr[index]);
            index++;
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

void TestStringList()
{
    T_LIST_LINKNODE listHead = {NULL, NULL};

    INIT_LIST_HEAD(&listHead);

    //insert node into list
    InsertStr2ListHead(&listHead, "first");
    InsertStr2ListHead(&listHead, "second");
    //MyPrintf("enter!!");
    
    // print list node
    PrintList(&listHead);

   // test list node order
    char* strArr[] = {
        "second",
        "first",
        NULL
    };
    AssertList(&listHead, strArr);
    
    FreeList(&listHead);
}

/***********************************************************************
                               stack api based list
************************************************************************/
E_BOOL_TYPE IsStackEmpty(PT_LIST_LINKNODE ptStack)
{
    return IsListEmpty(ptStack);
}

void PushEleOnStack(PT_LIST_LINKNODE ptStack, PT_NODE ptNode)
{
    list_add_tail(ptStack, &(ptNode->tLinkNode));
}

E_RETURN_TYPE PushStrOnStack(PT_LIST_LINKNODE ptStack, char* str)
{
    PT_NODE ptNode = NULL;
   
    //MyPrintf("Insert2List str is %s", str);
   
    ptNode = (PT_NODE) malloc(sizeof(T_NODE));
    if ( !ptNode )
    {
        return FALSE;
    }
   
    ptNode->str = strdup(str);
    if ( !(ptNode->str) )
    {
    	free(ptNode);
    	return FALSE;
    }

    PushEleOnStack(ptStack, ptNode);
    
    return TRUE;
}

// get top stack element, not pop
PT_NODE GetTopEleFromStack(PT_LIST_LINKNODE ptStack)
{
    PT_LIST_LINKNODE ptLinkNode = NULL;
    PT_NODE ptNode = NULL;
    
    //MyPrintf("enter pop0");
    if ( IsStackEmpty(ptStack) )
    {
        return NULL;
    }
    
    //MyPrintf("enter pop");
    ptLinkNode = ptStack->prev;
    ptNode = list_entry(ptLinkNode, T_NODE, tLinkNode);
    
    return ptNode;
}

// get top stack element, then pop it
PT_NODE PopEleFromStack(PT_LIST_LINKNODE ptStack)
{
    PT_NODE ptNode = NULL;

    ptNode = GetTopEleFromStack(ptStack);

    // top stack element, delete from stack
    if ( ptNode )
    {
        list_del(&(ptNode->tLinkNode));
    }
    
    return ptNode;
}

void TestStackCase()
{
    T_LIST_LINKNODE listHead = {NULL, NULL};

    INIT_LIST_HEAD(&listHead);

    //insert node into list
    PushStrOnStack(&listHead, "first");
    PushStrOnStack(&listHead, "second");
    //MyPrintf("enter!!");
    
    // print list node
    PrintList(&listHead);

   // test list node order
    char* strArr[] = {
        "first",
        "second",
        NULL
    };
    AssertList(&listHead, strArr);

    // pop stack 
    PT_NODE ptNode = NULL;
    ptNode = PopEleFromStack(&listHead);
    MyPrintf("pop ele is %s", ptNode->str);
    // print list node
    PrintList(&listHead);
    
    FreeListNode(ptNode);
    ptNode = NULL;
    
    FreeList(&listHead);
}


/***********************************************************************
                               generate reverse polish expression
************************************************************************/

typedef enum operEleType {
    OPERELE_TYPE_NONE = 0,
    OPERELE_TYPE_ADD,
    OPERELE_TYPE_MINUS,
    OPERELE_TYPE_MULTIPLE,
    OPERELE_TYPE_DIVIDE,
    OPERELE_TYPE_LEFT_BRACKET,
    OPERELE_TYPE_RIHGT_BRACKET,
    OPERELE_TYPE_NUMBER,
} E_OPERELE_TYPE;

typedef E_BOOL_TYPE (*CHECK_FOLLOW_VALID)(PT_STRING_OBJ ptStrObj);

typedef void (* DO_OPTYPE_ACTION)(PT_STRING_OBJ ptStrObj, PT_LIST_LINKNODE ptOperatorStack, PT_LIST_LINKNODE ptStack);

typedef struct operEleCharSet {
    char* szOptChars;
    E_BOOL_TYPE isMultiple;
} T_OPERELE_CHARSET, *PT_OPERELE_CHARSET;

typedef struct operEleAttrs {
    E_OPERELE_TYPE eOpType;
    T_OPERELE_CHARSET tOperEleCharSet;
    DO_OPTYPE_ACTION doOpTypeAction;
    CHECK_FOLLOW_VALID checkFollowValid;
} T_OPERELE_ATTRS, *PT_OPERELE_ATTRS; 



/********************************************************************************************************
                                                DO ACTION FUNCTIONS
*********************************************************************************************************/
void doAction_number(PT_STRING_OBJ ptEleStrObj, PT_LIST_LINKNODE ptOperatorStack, PT_LIST_LINKNODE ptStack)
{
    PushStrOnStack(ptStack, ptEleStrObj->szStr);
}

void doAction_add_minus(PT_STRING_OBJ ptEleStrObj, PT_LIST_LINKNODE ptOperatorStack, PT_LIST_LINKNODE ptStack)
{
    char szTemp[32] = {0};
    PT_NODE ptNode = NULL;

    while( ptNode = GetTopEleFromStack(ptOperatorStack) )
    {
        // compare to + and -, * / priority is high, Pop it from operator stack  
        // and push it on stack first
        if ( !strcmp(ptNode->str, "*") || !strcmp(ptNode->str, "/") )
        {
            ptNode = PopEleFromStack(ptOperatorStack);
            PushEleOnStack(ptStack, ptNode);
        }
        else
        {
            break;
        }
    }

    // push + - on operators stack
    PushStrOnStack(ptOperatorStack, ptEleStrObj->szStr);
}

void doAction_multiple_divide(PT_STRING_OBJ ptEleStrObj, PT_LIST_LINKNODE ptOperatorStack, PT_LIST_LINKNODE ptStack)
{
    // push * / on operators stack
    PushStrOnStack(ptOperatorStack, ptEleStrObj->szStr);
}

void doAction_left_bracket(PT_STRING_OBJ ptEleStrObj, PT_LIST_LINKNODE ptOperatorStack, PT_LIST_LINKNODE ptStack)
{
    // push ( on operators stack
    PushStrOnStack(ptOperatorStack, ptEleStrObj->szStr);
}

void doAction_right_bracket(PT_STRING_OBJ ptEleStrObj, PT_LIST_LINKNODE ptOperatorStack, PT_LIST_LINKNODE ptStack)
{
    PT_NODE ptNode = NULL;

    while( ptNode = GetTopEleFromStack(ptOperatorStack) )
    {
        // for  (xx),  the operands in xx has highest priority, so those operands must pops
        if ( strcmp(ptNode->str, "(") )
        {
            ptNode = PopEleFromStack(ptOperatorStack);
            PushEleOnStack(ptStack, ptNode);                    
        }
        else
        {
            // for ( , pop it and discard it
            PopEleFromStack(ptOperatorStack);
            break;
        }
    }
}

/********************************************************************************************************
                                                CHECK FOLLOW VALID FUNCTIONS
*********************************************************************************************************/
// current element is number, check follow string is valid?
E_BOOL_TYPE checkFolowValid_number(PT_STRING_OBJ ptStrObj)
{
    char cChar = 0;

    cChar = GetCharFromStr_purely(ptStrObj);

    // number can be tail of expression
    if ( cChar == '\0' )
    {
        return TRUE;
    }
    // number as operand
    else if ( strchr("+-*/", cChar) )
    {
        return TRUE;
    }
    // number as right operand, following ), for example, (1+3)
    else if ( cChar == ')' )
    {
        return TRUE;
    }
    else
    {
    }

    return FALSE;
}

// current element is operator + - * /, check follow string is valid?
E_BOOL_TYPE checkFolowValid_operator(PT_STRING_OBJ ptStrObj)
{
    char cChar = 0;

    cChar = GetCharFromStr_purely(ptStrObj);

    // operator next element must be number
    if ( isdigit(cChar) )
    {
        return TRUE;
    }

    return FALSE;
}

// current element is operator (, check follow string is valid?
E_BOOL_TYPE checkFolowValid_left_bracket(PT_STRING_OBJ ptStrObj)
{
    char cChar = 0;

    cChar = GetCharFromStr_purely(ptStrObj);

    // ( following elment can be number
    if ( isdigit(cChar) )
    {
        return TRUE;
    }
    // ( following elment can be (, for example, ((1+2))
    else if ( cChar == '(' )
    {
        return TRUE;
    }
    else
    {
    }

    return FALSE;
}

// current element is operator ), check follow string is valid?
E_BOOL_TYPE checkFolowValid_right_bracket(PT_STRING_OBJ ptStrObj)
{
    char cChar = 0;

    cChar = GetCharFromStr_purely(ptStrObj);

    // )  can be tail of expression
    if ( cChar == '\0' )
    {
        return TRUE;
    }
    //) following element can be operator
    else if ( strchr("+-*/", cChar) )
    {
        return TRUE;
    }
    // ) following can be itself ), for example, (1+3)
    else if ( cChar == ')' )
    {
        return TRUE;
    }
    else
    {
    }

    return FALSE;
}


/*
arithematic expression is a portion of mathematic expression, 
mathematic expression is defined as

https://en.wikipedia.org/wiki/Expression_%28mathematics%29
In mathematics, an expression (or mathematical expression) is a finite combination of symbols that is well-formed according to rules that depend on the context. 
Mathematical symbols can designate numbers (constants), variables, operations, functions, punctuation, grouping, and other aspects of logical syntax.

from the definition, we get several symbol that relate to arithmetic expresion:
1. number(constants) --- 123
2. operations --- + - * /
3. grouping --- parenthesis ()
*/
T_OPERELE_ATTRS g_oprEleType_attrs[] = {
    {OPERELE_TYPE_NUMBER,                     {"0123456789", TRUE},  doAction_number,           checkFolowValid_number},
    {OPERELE_TYPE_ADD,                           {"+", FALSE},                doAction_add_minus,       checkFolowValid_operator},
    {OPERELE_TYPE_MINUS,                        {"-", FALSE},                doAction_add_minus,        checkFolowValid_operator},
    {OPERELE_TYPE_MULTIPLE,                    {"*", FALSE},                doAction_multiple_divide, checkFolowValid_operator},
    {OPERELE_TYPE_DIVIDE,                       {"/", FALSE},                doAction_multiple_divide, checkFolowValid_operator},
    {OPERELE_TYPE_LEFT_BRACKET,            {"(", FALSE},                doAction_left_bracket,      checkFolowValid_left_bracket},
    {OPERELE_TYPE_RIHGT_BRACKET,         {")", FALSE},                doAction_right_bracket,    checkFolowValid_right_bracket},
    {OPERELE_TYPE_NONE,                          {NULL, FALSE},             NULL},    
};

int findOprEleIndex(char cChar)
{
    int iIndex = 0;

    for (;g_oprEleType_attrs[iIndex].eOpType!=OPERELE_TYPE_NONE; iIndex++)
    {
        if ( strchr(g_oprEleType_attrs[iIndex].tOperEleCharSet.szOptChars, cChar)  )
        {
            return iIndex;
        }
    }

    // cannot find normal operand type, return last OPERAND_TYPE_NONE iIndex
    return iIndex;
}

// get operation element string
E_BOOL_TYPE GetOperEleString(PT_STRING_OBJ ptEleStrObj, PT_STRING_OBJ ptStrObj)
{
    int iIndex = 0;
    char cChar = 0;
    char* szCharSet = NULL;

    if ( !ptEleStrObj || !ptStrObj )
    {
        return FALSE;
    }

    cChar = GetCharFromStr(ptStrObj);
    if ( !cChar )
    {
        return FALSE;
    }
    
    iIndex = findOprEleIndex(cChar);
    // char is illegal, ie, arithmetic is invalid , warning
    if ( g_oprEleType_attrs[iIndex].eOpType == OPERELE_TYPE_NONE )
    {
        StopWithMsg("char(%c) is illegal, ie, arithmetic is invalid , warning", cChar);
    }

    // save first element char
    AddChar2StrObj(ptEleStrObj, cChar);

    // if operation element char set can be multiple, detect whether next char is in this char set
    if ( g_oprEleType_attrs[iIndex].tOperEleCharSet.isMultiple )
    {
        szCharSet = g_oprEleType_attrs[iIndex].tOperEleCharSet.szOptChars;
        
        // detect whether next char is in this char set
        while( cChar = GetCharFromStr_purely(ptStrObj) )
        {
            // in this char set!save it too.
            if ( strchr(szCharSet, cChar) )
            {
                 AddChar2StrObj(ptEleStrObj, cChar);
                 
                 // discard current char from string
                 GetCharFromStr(ptStrObj);
            }
            else
            {
                // next char is not digit, do not read, break
                break;
            }
        }
    }

    return TRUE;
}

// translate arithmetic expression to reverse polish expression, ie postfix epression
void Translate2PostfixExp(char* str, PT_LIST_LINKNODE ptStack)
{
    T_LIST_LINKNODE tOperatorStack = {NULL};
    PT_LIST_LINKNODE ptOperatorStack =  &tOperatorStack;

    T_STRING_OBJ tStrObj = {0};
    PT_STRING_OBJ ptStrObj = &tStrObj;

    T_STRING_OBJ tEleStrObj = {0};
    PT_STRING_OBJ ptEleStrObj = &tEleStrObj;

    char cChar = 0;
    PT_NODE ptNode = NULL;
    int iIndex = -1;

    InitStrObjStruct(ptStrObj, str, FALSE);

    INIT_LIST_HEAD(ptOperatorStack);

    // analyze string, translate 2 polish expression
    InitStrObjStruct(ptEleStrObj, "", TRUE);
    while( GetOperEleString(ptEleStrObj, ptStrObj) )
    {
        iIndex = findOprEleIndex(ptEleStrObj->szStr[0]);

        // element is illegal, ie, arithmetic is invalid , warning
        if ( g_oprEleType_attrs[iIndex].eOpType == OPERELE_TYPE_NONE )
        {
            StopWithMsg("element is illegal, ie, arithmetic is invalid , warning");
        }

        // handle this operation element, relate to Operator Stack and Stack( reverse polish expression)
        g_oprEleType_attrs[iIndex].doOpTypeAction(ptEleStrObj, ptOperatorStack, ptStack);

        //check following validity
        if ( !g_oprEleType_attrs[iIndex].checkFollowValid(ptStrObj) )
        {
            MyPrintf("!! this element is (%s), the following is illegal. this expression is illegal !!", ptEleStrObj->szStr);
        }

        FreeStrObjMem(ptEleStrObj);
        InitStrObjStruct(ptEleStrObj, "", TRUE);
    }
    FreeStrObjMem(ptEleStrObj);

    // if oprands stack is not empty, pop and save
    // for example, a+b-c
    // stack is a b c
    // operand stack is  + -
    // after clear operand stack, stack is  a b c - + ,  
    // left operand is be first computed if operands with equal right is adjacent
    // math term is  left associative law
    while( !IsStackEmpty(ptOperatorStack) )
    {
        ptNode = PopEleFromStack(ptOperatorStack);
        PushEleOnStack(ptStack, ptNode);
    }

    FreeList(ptOperatorStack);
    ptOperatorStack = NULL;
}

void TestGenReversePolishCase_add_plus()
{
    T_LIST_LINKNODE listHead = {NULL, NULL};

    INIT_LIST_HEAD(&listHead);

    Translate2PostfixExp("1+2-3", &listHead);
    PrintList(&listHead);

   // test list node order
    char* strArr[] = {
        "1",
        "2",
        "3",
        "-",
        "+",
        NULL
    };
    AssertList(&listHead, strArr);

    FreeList(&listHead);
}

void TestGenReversePolishCase_multiple_divide()
{
    T_LIST_LINKNODE listHead = {NULL, NULL};

    INIT_LIST_HEAD(&listHead);

    Translate2PostfixExp("1*2/3", &listHead);
    PrintList(&listHead);

   // test list node order
    char* strArr[] = {
        "1",
        "2",
        "3",
        "/",
        "*",
        NULL
    };
    AssertList(&listHead, strArr);

    FreeList(&listHead);
}

void TestGenReversePolishCase_hybrid_diffRight_Operands()
{
    T_LIST_LINKNODE listHead = {NULL, NULL};

    // minus before divide operand
    INIT_LIST_HEAD(&listHead);

    Translate2PostfixExp("1-2/3", &listHead);
    PrintList(&listHead);

   // test list node order
    char* strArr[] = {
        "1",
        "2",
        "3",
        "/",
        "-",
        NULL
    };
    AssertList(&listHead, strArr);

    FreeList(&listHead);


    // divide before minus operand
    INIT_LIST_HEAD(&listHead);

    Translate2PostfixExp("2/3-1", &listHead);
    PrintList(&listHead);

   // test list node order
    char* strArr1[] = {
        "2",
        "3",
        "/",
        "1",
        "-",
        NULL
    };
    AssertList(&listHead, strArr1);

    FreeList(&listHead);
}

void TestGenReversePolishCase_brace_express()
{
    T_LIST_LINKNODE listHead = {NULL, NULL};

    INIT_LIST_HEAD(&listHead);

    Translate2PostfixExp("(1+2)-3", &listHead);
    PrintList(&listHead);

   // test list node order
    char* strArr[] = {
        "1",
        "2",
        "+",
        "3",
        "-",
        NULL
    };
    AssertList(&listHead, strArr);

    FreeList(&listHead);

    /**********  complicate case  ************/
    INIT_LIST_HEAD(&listHead);

    Translate2PostfixExp("(4*1+2)-3", &listHead);
    PrintList(&listHead);

   // test list node order
    char* strArr1[] = {
        "4",
        "1",
        "*",
        "2",
        "+",
        "3",
        "-",
        NULL
    };
    AssertList(&listHead, strArr1);

    FreeList(&listHead);
}

void TestGenReversePolishCase_multiple_numbers()
{
    T_LIST_LINKNODE listHead = {NULL, NULL};

    INIT_LIST_HEAD(&listHead);
    //MyPrintf("enter multiple numbers");
    Translate2PostfixExp("100*200/300", &listHead);

    PrintList(&listHead);

   // test list node order
    char* strArr[] = {
        "100",
        "200",
        "300",
        "/",
        "*",
        NULL
    };
    AssertList(&listHead, strArr);

    FreeList(&listHead);
}

void TestGenReversePolishCase_expression_exception()
{
    T_LIST_LINKNODE listHead = {NULL, NULL};

    INIT_LIST_HEAD(&listHead);
    //MyPrintf("enter multiple numbers");
    Translate2PostfixExp("100++1", &listHead);

    PrintList(&listHead);

    // although translate produce such result, firstly 100++1 is not illegal arithmetic expression,
    // translate process shall thrown this exception
    // test list node order
    char* strArr[] = {
        "100",
        "1",
        "+",
        "+",
        NULL
    };
    AssertList(&listHead, strArr);

    FreeList(&listHead);
}


void TestGenReversePolishCase()
{
    TestGenReversePolishCase_add_plus();

    TestGenReversePolishCase_multiple_divide();

    TestGenReversePolishCase_hybrid_diffRight_Operands();

    TestGenReversePolishCase_brace_express();
    
    //MyPrintf("enter multiple numbers111");
    TestGenReversePolishCase_multiple_numbers();

    TestGenReversePolishCase_expression_exception();
}

/***********************************************************************
                               calc reverse polish expression
************************************************************************/

typedef int (*OPERATOR_FUNC)(int a, int b);

typedef struct operatorAttrs{
    char* szOperator;
    OPERATOR_FUNC operatorFunc;
} T_OPERATOR_ATTRS, *PT_OPERATOR_ATTRS;

int operator_add(int a, int b)
{
    int ret = 0;

    ret = a + b;

    return ret;
}

int operator_minus(int a, int b)
{
    int ret = 0;

    ret = a - b;

    return ret;
}

int operator_multiple(int a, int b)
{
    int ret = 0;

    ret = a * b;

    return ret;
}

int operator_divide(int a, int b)
{
    int ret = 0;

    ret = a / b;

    return ret;
}

T_OPERATOR_ATTRS g_operator_atrrs[] = {
    {"+",  operator_add},
    {"-",  operator_minus},
    {"*",  operator_multiple},
    {"/",  operator_divide},    
    {NULL,  NULL},    
};

OPERATOR_FUNC findOperatorMethod(char* szOperator)
{
    int iIndex = 0;

    for ( ;g_operator_atrrs[iIndex].szOperator; iIndex++ )
    {
        if ( !strcmp(szOperator, g_operator_atrrs[iIndex].szOperator) )
        {
            return g_operator_atrrs[iIndex].operatorFunc;
        }
    }

    return NULL;
}

int ClacReversePlishExp(PT_LIST_LINKNODE ptListHead)
{
    T_LIST_LINKNODE tNumberStack = {NULL, NULL};
    PT_LIST_LINKNODE ptNumberStack = &tNumberStack;
    PT_NODE ptNode = NULL;
    PT_NODE ptOperandLeft = NULL;
    PT_NODE ptOperandRight = NULL;
    OPERATOR_FUNC operatorFunc = NULL;
    int ret = 0;

    INIT_LIST_HEAD(ptNumberStack);

    // from head, scan list (reverse polish expression)
    while( ptNode = List_DetachFirstNode(ptListHead) )
    {
        // if node is number, push it on number stack 
        if ( isdigit(ptNode->str[0]) )
        {
            ptNode->number = atoi(ptNode->str);
            PushEleOnStack(ptNumberStack, ptNode);
        }
        // if node is operator, pop two element from reverse polish stack
        else if ( strchr("+-*/", ptNode->str[0]) )
        {
            operatorFunc = findOperatorMethod(ptNode->str);
            if ( operatorFunc )
            {
                ptOperandRight = PopEleFromStack(ptNumberStack);
                ptOperandLeft = GetTopEleFromStack(ptNumberStack);
                
                ret = operatorFunc(ptOperandLeft->number, ptOperandRight->number);

                // the element poped is obsolete, must be freed
                FreeListNode(ptOperandRight);

                // save the calc result to stack top element
                ptOperandLeft->number = ret;
            }
        }
        else
        {
        }
    }

    ptNode = List_DetachFirstNode(ptNumberStack);
    ret = ptNode->number;
    FreeListNode(ptNode);

    FreeList(ptNumberStack);

    return ret;
}

void TestClacReversePolish_add_minus()
{
    T_LIST_LINKNODE listHead = {NULL, NULL};

    INIT_LIST_HEAD(&listHead);
    //MyPrintf("enter multiple numbers");
    Translate2PostfixExp("100+1", &listHead);

    PrintList(&listHead);

    int ret = ClacReversePlishExp(&listHead);
    MyAssert((ret == 101), "add operator calc failed.");
    MyPrintf("arithmetic expression=(%s), result=(%d)", "100+1", ret);

    FreeList(&listHead);
}

void TestClacReversePolish()
{
    TestClacReversePolish_add_minus();
}

int main(void)
{
    // test list
    //TestStringList();

    // test stack api
    //TestStackCase();

    // test function -- reverse polish calc
    //TestGenReversePolishCase();

    //test function -- calc reverse polish expression 
    TestClacReversePolish();
    
    return 0;
}



