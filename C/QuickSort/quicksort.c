
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
						PT_LIST_LINKNODE ptPrevLink = (ptListHead);\
						PT_LIST_LINKNODE ptNextLink = (ptListHead)->next;\
                        _list_add((ptListNewLink), (ptPrevLink), (ptNextLink));\
                        } while(0)

// add new list node to  list tail
#define list_add_tail(ptListHead, ptListNewLink) do {\
						PT_LIST_LINKNODE ptPrevLink = ((ptListHead)->prev);\
						PT_LIST_LINKNODE ptNextLink = ptListHead;\
                        _list_add((ptListNewLink), (ptPrevLink), (ptNextLink));\
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
    //system("pause");
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
                               QuickSort  function
************************************************************************/

// list quick sort core function
void _List_QuickSort(PT_LIST_LINKNODE ptLinkFirst, PT_LIST_LINKNODE ptLinkLast)
{
    // center node that will partion list into two part, 
    // left nodes all are less than it, 
    // right nodes all are greater than it
    PT_LIST_LINKNODE ptLinkPivot = NULL; 
    char* szPivot = NULL;

    // the left and right cursor used in one comparing procedure
    PT_LIST_LINKNODE ptLinkLeft = NULL;
    PT_LIST_LINKNODE ptLinkRight = NULL;

    PT_NODE ptNodePivot = NULL;
    PT_NODE ptNodeLeft = NULL;
    PT_NODE ptNodeRight = NULL;

    // recurse to the ceasing condtion, 
    // one node is the list, list is ordered.
    if ( ptLinkFirst == ptLinkLast )
    {
        return ;
    }

    // cursor initialization
    ptLinkLeft = ptLinkFirst;
    ptLinkRight = ptLinkLast;

    // select first node as the pivot ( center pointer )
    ptLinkPivot = ptLinkLeft;
    ptNodePivot = list_entry(ptLinkPivot, T_NODE, tLinkNode);
    szPivot = ptNodePivot->str;

    while( ptLinkLeft!= ptLinkRight )
    {
        // search first node less than pivot from right end
        while( ptLinkLeft!= ptLinkRight )
        {
            ptNodeRight = list_entry(ptLinkRight, T_NODE, tLinkNode);

            // find it
            if ( strcmp(ptNodeRight->str, szPivot) < 0 )
            {
                // save the string to pivot pointer node
                // note, this time pivot pointer is ptLinkLeft
                ptNodeLeft = list_entry(ptLinkLeft, T_NODE, tLinkNode);
                ptNodeLeft->str = ptNodeRight->str;

                // now pivot node is less than szPivot,  so ptLinkLeft node is not pivot any more, should set ptLinkLeft to its next node
                ptLinkLeft = ptLinkLeft->next;

                // right searching over
                break;
            }
            // not found yet
            else
            {
                //set right node to its previous node, for next comparing
                ptLinkRight = ptLinkRight->prev;
            }
        }

        // search first node greater than pivot from left end
        while( ptLinkLeft!= ptLinkRight )
        {
            ptNodeLeft = list_entry(ptLinkLeft, T_NODE, tLinkNode);

            // find it
            if ( strcmp(ptNodeLeft->str, szPivot) > 0 )
            {
                // save the string to pivot pointer node, 
                // note after first while, ptNodePivot is ptLinkRight
                ptNodeRight= list_entry(ptLinkRight, T_NODE, tLinkNode);
                ptNodeRight->str = ptNodeLeft->str;

                // now pivot node is greater than szPivot,  so ptLinkRight node is not pivot any more, should set ptLinkRight to its previous node
                ptLinkRight = ptLinkRight->prev;

                // left searching over
                break;
            }
            // not found yet
            else
            {
                //set right node to its next node, for next comparing
                ptLinkLeft = ptLinkLeft->next;
            }
        }
    }

    //now center pointer node(pivot) is ptLinkLeft, which is equal to ptLinkRight
    //save pivot node string
    ptLinkPivot = ptLinkLeft;
    ptNodePivot = list_entry(ptLinkPivot, T_NODE, tLinkNode);
    ptNodePivot->str = szPivot;

    //now recursively, quick sort pivot left list
    if ( ptLinkPivot != ptLinkFirst )
    {
        _List_QuickSort( ptLinkFirst, ptLinkPivot->prev );
    }

    //now recursively,  quick sort pivot right list
    if ( ptLinkPivot != ptLinkLast )
    {
        _List_QuickSort( ptLinkPivot->next, ptLinkLast );
    }
}

void QuickSortList(PT_LIST_LINKNODE ptListHead)
{
    PT_LIST_LINKNODE ptLinkFirst = NULL;
    PT_LIST_LINKNODE ptLinkLast = NULL;

    if ( IsListEmpty(ptListHead) )
    {
        return ;
    }

    ptLinkFirst = ptListHead->next;
    ptLinkLast = ptListHead->prev;
    
    _List_QuickSort(ptLinkFirst, ptLinkLast);
}

void TestQuickSortCase()
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

    MyPrintf("----- now quick sort --------");
    
    QuickSortList(&listHead);

    // print list node
    PrintList(&listHead);

   // test list node order
    char* strArr1[] = {
        "first",
        "second",
        NULL
    };
    AssertList(&listHead, strArr1);
    
    
    FreeList(&listHead);
}


int main(void)
{
    // test list
    //TestStringList();

    // test quick sort
   TestQuickSortCase();
    
    return 0;
}



