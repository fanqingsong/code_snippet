
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

/***********************************************************************
                                LIST fundemental function
************************************************************************/
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

//create a node with string str and insert node into list
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

// insert node into list head position
PT_NODE InsertNode2ListHead(PT_NODE ptHeadNode, PT_NODE ptNode)
{
    PT_NODE ptFirst = NULL;
      
    ptFirst = ptHeadNode->next;
    
    ptHeadNode->next = ptNode;
    ptNode->next = ptFirst;

    return ptHeadNode;
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

// compare two string, if str1 is larger than str2, return true, otherwise false
E_BOOL_TYPE StrCmpLarger(char* str1, char* str2)
{
    if ( !str1 || !str2 )
    {
        StopWithMsg("strcmplarger function argments ");
    }

    if ( strcmp( str1, str2 ) > 0 )
    {
        return TRUE;
    }

    return FALSE;
}

// compare two string, if str1 is less than str2, return true, otherwise false
E_BOOL_TYPE StrCmpLess(char* str1, char* str2)
{
    if ( !str1 || !str2 )
    {
        StopWithMsg("strcmplarger function argments ");
    }

    if ( strcmp( str1, str2 ) < 0 )
    {
        return TRUE;
    }

    return FALSE;
}

typedef E_BOOL_TYPE (*STRCMPFUNC)(char* str1, char* str2);

/***********************************************************************
                                selecting sort method
************************************************************************/

// find specific node by strcmpfunc and detach it from list
PT_NODE FindAndDetachNode(PT_NODE ptHeadNode, STRCMPFUNC strcmpfunc )
{
    PT_NODE ptTargetNode = NULL;
    PT_NODE ptPreMax = NULL;
    PT_NODE ptCurNode = NULL;
    PT_NODE ptPreNode = NULL;

    ptTargetNode = ptHeadNode->next;
    ptPreMax = ptHeadNode;

    ptCurNode = ptHeadNode->next;
    ptPreNode = ptHeadNode;
    while( ptCurNode )
    {
        // current node string is larger than specific node string, record it
        if ( strcmpfunc(ptCurNode->str, ptTargetNode->str) )
        {
            ptTargetNode = ptCurNode;
            ptPreMax = ptPreNode;
        }

        ptPreNode = ptCurNode;
        ptCurNode = ptCurNode->next;
    }

    // specific node found, detach it from list
    if ( ptTargetNode )
    {
        ptPreMax->next = ptTargetNode->next;
        ptTargetNode->next = NULL;
    }

    // return specific node
    return ptTargetNode;
}

// sort list by specific order by strcmpfunc
void SortListWithSelectMethod(PT_NODE ptHeadNode, STRCMPFUNC strcmpfunc)
{
    T_NODE tNewHead = {NULL, NULL};
    PT_NODE ptNode = NULL;

    // selection sort method
    while( TRUE )
    {
        // find target node and detach it from list
        ptNode = FindAndDetachNode(ptHeadNode, strcmpfunc);
        if ( !ptNode )
        {
            break;
        }

        // insert target node into new list from head
        InsertNode2ListHead(&tNewHead, ptNode);
    }

    // reset head node to new list
    ptHeadNode->next = tNewHead.next;
    tNewHead.next = NULL;
}

void TestList_SelectionMethod()
{
    T_NODE headNode = {NULL, NULL};

    //insert node into list
    Insert2List(&headNode, "first");
    Insert2List(&headNode, "second");

    // print list node
    PrintList(&headNode);

   // test list node order
    char* strArr[] = {
        "second",
        "first",
        NULL
    };
    AssertList(&headNode, strArr);

    // order list, from small to big
    SortListWithSelectMethod(&headNode, StrCmpLarger);
    // print list node
    PrintList(&headNode);
    
    // test list node new order
    char* strArr1[] = {
        "first",
        "second",
        NULL
    };
   AssertList(&headNode, strArr1);

    // order list, from big to small
    SortListWithSelectMethod(&headNode, StrCmpLess);
    // print list node
    PrintList(&headNode);
    // test list node new order
    char* strArr2[] = {
        "second",
        "first",
        NULL
    };
    AssertList(&headNode, strArr2);
    
    FreeList(&headNode);
}

/***********************************************************************
                                bubble sort method
************************************************************************/

// bubble list by strcmpfunc and detach last from list
PT_NODE BubbleAndDetachLast(PT_NODE ptHeadNode, STRCMPFUNC strcmpfunc)
{
    PT_NODE ptCurNode = NULL;
    PT_NODE ptPreNode = NULL;
    PT_NODE ptNextNode = NULL;

    ptCurNode = ptHeadNode->next;
    ptPreNode = ptHeadNode;
    while( ptCurNode )
    {
        ptNextNode = ptCurNode->next;
        
        // reach list tail
        if ( !ptNextNode )
        {
            break;
        }
    
        // current node string is larger than next node string, swap it
        if ( strcmpfunc(ptCurNode->str, ptNextNode->str) )
        {
            ptPreNode->next = ptNextNode;
            ptCurNode->next = ptNextNode->next;
            ptNextNode->next = ptCurNode;

            // reset current node's previous node
            ptPreNode = ptNextNode;
        }
        else
        {
            ptPreNode = ptCurNode;
            ptCurNode = ptCurNode->next;
        }
    }

    //detach current node from list
    ptPreNode->next = NULL;

    // current node is the last node, return it
    return ptCurNode;
 
}

// sort list by specific order by strcmpfunc
void SortListWithBubbleMethod(PT_NODE ptHeadNode, STRCMPFUNC strcmpfunc)
{
    T_NODE tNewHead = {NULL, NULL};
    PT_NODE ptNode = NULL;

    // selection sort method
    while( TRUE )
    {
        // bubble list and detach last from list
        ptNode = BubbleAndDetachLast(ptHeadNode, strcmpfunc);
        if ( !ptNode )
        {
            break;
        }

        // insert max node into new list from head
        InsertNode2ListHead(&tNewHead, ptNode);
    }

    // reset head node to new list
    ptHeadNode->next = tNewHead.next;
    tNewHead.next = NULL;
}

void TestList_BubbleMethod()
{
    T_NODE headNode = {NULL, NULL};

    //insert node into list
    Insert2List(&headNode, "first");
    Insert2List(&headNode, "second");

    // print list node
    PrintList(&headNode);

   // test list node order
    char* strArr[] = {
        "second",
        "first",
        NULL
    };
    AssertList(&headNode, strArr);

    // order list, from small to big
    SortListWithBubbleMethod(&headNode, StrCmpLarger);
    // print list node
    PrintList(&headNode);
    
    // test list node new order
    char* strArr1[] = {
        "first",
        "second",
        NULL
    };
   AssertList(&headNode, strArr1);

    // order list, from big to small
    SortListWithBubbleMethod(&headNode, StrCmpLess);
    // print list node
    PrintList(&headNode);
    // test list node new order
    char* strArr2[] = {
        "second",
        "first",
        NULL
    };
    AssertList(&headNode, strArr2);
    
    FreeList(&headNode);
}

/***********************************************************************
                                inserting sort method
************************************************************************/
PT_NODE DetachFirstNode(PT_NODE ptHeadNode)
{
    PT_NODE ptFirstNode = NULL;

    ptFirstNode = ptHeadNode->next;

    // detach first node from list
    if ( ptFirstNode )
    {
        ptHeadNode->next = ptFirstNode->next;
    }

    return ptFirstNode;
}

// insert node into list by inserting sort method
void InsertNode2ListByInsertMethod(PT_NODE ptHeadNode, PT_NODE ptNode, STRCMPFUNC strcmpfunc)
{
    PT_NODE ptPrevNode = NULL;
    PT_NODE ptCurNode = NULL;

    ptPrevNode = ptHeadNode;
    ptCurNode = ptPrevNode->next;

    while( ptCurNode )
    {
        if ( strcmpfunc(ptCurNode->str, ptNode->str) )
        {
            ptPrevNode->next = ptNode;
            ptNode->next = ptCurNode;

            // insert ok, let's leave
            break;
        }
        else
        {
            ptPrevNode = ptCurNode;
            ptCurNode = ptCurNode->next;
        }
    }

    // current node is NULL, previous node is last node of list, 
    // ie, insert not ok,  the node shall be added to tail
    if ( !ptCurNode )
    {
        ptPrevNode->next = ptNode;
        ptNode->next = NULL;
    }
}

// sort list by specific order by strcmpfunc
void SortListWithInsertMethod(PT_NODE ptHeadNode, STRCMPFUNC strcmpfunc)
{
    T_NODE tNewHead = {NULL, NULL};
    PT_NODE ptNode = NULL;

    // selection sort method
    while( TRUE )
    {
        // get first node from list
        ptNode = DetachFirstNode(ptHeadNode);
        if ( !ptNode )
        {
            break;
        }

        // insert the node into new list by inserting method
        InsertNode2ListByInsertMethod(&tNewHead, ptNode, strcmpfunc);
    }

    // reset head node to new list
    ptHeadNode->next = tNewHead.next;
    tNewHead.next = NULL;
}


void TestList_InsertingMethod()
{
    T_NODE headNode = {NULL, NULL};

    //insert node into list
    Insert2List(&headNode, "first");
    Insert2List(&headNode, "second");

    // print list node
    PrintList(&headNode);

   // test list node order
    char* strArr[] = {
        "second",
        "first",
        NULL
    };
    AssertList(&headNode, strArr);

    // order list, from small to big
    SortListWithInsertMethod(&headNode, StrCmpLarger);
    // print list node
    PrintList(&headNode);
    
    // test list node new order
    char* strArr1[] = {
        "first",
        "second",
        NULL
    };
   AssertList(&headNode, strArr1);

    // order list, from big to small
    SortListWithInsertMethod(&headNode, StrCmpLess);
    // print list node
    PrintList(&headNode);
    // test list node new order
    char* strArr2[] = {
        "second",
        "first",
        NULL
    };
    AssertList(&headNode, strArr2);
    
    FreeList(&headNode);
}

/***********************************************************************
                                Test case area
************************************************************************/
// list 链表操作测试用例
void TestListCase()
{
    //TestList_SelectionMethod();
    //TestList_BubbleMethod();
    TestList_InsertingMethod();
}

int main(void)
{
    // test list function
    TestListCase();
   
    return 0;
}
