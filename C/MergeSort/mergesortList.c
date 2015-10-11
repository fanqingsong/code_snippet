
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

// list for each
#define list_for_each(ptListHead, ptLinkNode) \
                        (ptLinkNode) = (ptListHead)->next;\
                        for(;(ptLinkNode) != (ptListHead); (ptLinkNode)=(ptLinkNode)->next)

// list for each reverse
#define list_for_each_reverse(ptListHead, ptLinkNode) \
                        (ptLinkNode) = (ptListHead)->prev;\
                        for(;(ptLinkNode) != (ptListHead); (ptLinkNode)=(ptLinkNode)->prev)

// list for each safe -- prevent breaking list after call list_del
#define list_for_each_safe(ptListHead, ptLinkNode, ptNextCache) \
                        (ptLinkNode) = (ptListHead)->next;\
                        for(;(ptNextCache)=(ptLinkNode)->next, (ptLinkNode) != (ptListHead); (ptLinkNode)=(ptNextCache) )

// list for each safe reversely -- prevent breaking list after call list_del
#define list_for_each_safe_reverse(ptListHead, ptLinkNode, ptNextCache) \
                        (ptLinkNode) = (ptListHead)->prev;\
                        for(;(ptNextCache)=(ptLinkNode)->prevt, (ptLinkNode) != (ptListHead); (ptLinkNode)=(ptNextCache) )

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

// for a list which every node is store a list head 
typedef struct node_listHead{
    T_LIST_LINKNODE tLinkNode; // current node link node
    T_LIST_LINKNODE tListHead; // sub list head
} T_NODE_LISTHEAD, *PT_NODE_LISTHEAD;

typedef enum returnType {
    FAIL = 0,
    SUCCESS,
} E_RETURN_TYPE;
    
typedef enum boolType {
    FALSE = 0,
    TRUE,
} E_BOOL_TYPE;



/* ------------------------------ list linux API  --------------------------------- */

// initialize the head and tail of list head as self
static inline void INIT_LIST_HEAD(PT_LIST_LINKNODE ptListHead)
{
    ptListHead->next = ptListHead;
    ptListHead->prev = ptListHead;
}

// insert new link node between previous link node and next link node
static inline void _list_add(PT_LIST_LINKNODE ptNewLink,
                  PT_LIST_LINKNODE ptPrevLink,
                  PT_LIST_LINKNODE ptNextLink)
{
    // splice new link and next link
    ptNewLink->next = ptNextLink;
    ptNextLink->prev = ptNewLink;

    // splice new link and previous link
    ptNewLink->prev = ptPrevLink;
    ptPrevLink->next = ptNewLink;
}

// delete the specific link node from list
static inline void list_del(PT_LIST_LINKNODE ptLinkNode)
{
    ptLinkNode->prev->next = ptLinkNode->next;
    ptLinkNode->next->prev = ptLinkNode->prev;
    
    ptLinkNode->prev = NULL;
    ptLinkNode->next = NULL;
}

// add new list node to  list head
static inline void list_add_head(PT_LIST_LINKNODE ptListHead,  PT_LIST_LINKNODE ptListNewLink)
{
    PT_LIST_LINKNODE ptPrevLink = ptListHead;
    PT_LIST_LINKNODE ptNextLink = ptListHead->next;
    
    _list_add(ptListNewLink,  ptPrevLink, ptNextLink);
}


// add new list node to  list tail
static inline void list_add_tail(PT_LIST_LINKNODE ptListHead, PT_LIST_LINKNODE ptListNewLink)
{
    PT_LIST_LINKNODE ptPrevLink = ptListHead->prev;
    PT_LIST_LINKNODE ptNextLink = ptListHead;
    
    _list_add(ptListNewLink, ptPrevLink, ptNextLink);
}


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

    // exception handle, list is empty or error
    if ( !ptListHead->next || !ptListHead->prev )
    {
        return;
    }

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


PT_NODE_LISTHEAD GetNode_ListHead()
{
    PT_NODE_LISTHEAD ptNodeListHead = NULL;

    ptNodeListHead  = malloc(sizeof(T_NODE_LISTHEAD));
    if ( !ptNodeListHead )
    {
        return NULL;
    }

    INIT_LIST_HEAD(&(ptNodeListHead->tListHead));

    return ptNodeListHead;
}

void FreeNode_ListHead(PT_NODE_LISTHEAD * pptNodeListHead)
{
    PT_NODE_LISTHEAD ptNodeListHead = *pptNodeListHead;

    FreeList(&(ptNodeListHead->tListHead));
    
    ptNodeListHead->tLinkNode.next = NULL;
    ptNodeListHead->tLinkNode.prev = NULL;
    
    if ( ptNodeListHead )
    {
        free(ptNodeListHead);
    }

    *pptNodeListHead = NULL;
}

PT_LIST_LINKNODE List_DetachFirstLink(PT_LIST_LINKNODE ptListHead)
{
    PT_LIST_LINKNODE ptLinkNode = NULL;

    if ( IsListEmpty(ptListHead) )
    {
        return NULL;
    }

    ptLinkNode = ptListHead->next;
    list_del(ptLinkNode);

    return ptLinkNode;
}

PT_LIST_LINKNODE List_DetachLastLink(PT_LIST_LINKNODE ptListHead)
{
    PT_LIST_LINKNODE ptLinkNode = NULL;
    
    if ( IsListEmpty(ptListHead) )
    {
        return NULL;
    }
    
    ptLinkNode = ptListHead->prev;
    list_del(ptLinkNode);
    
    return ptLinkNode;
}

void List_AddLink2Head(PT_LIST_LINKNODE ptListHead, PT_LIST_LINKNODE ptLinkNode)
{
    list_add_head(ptListHead, ptLinkNode);
}

void List_AddLink2Tail(PT_LIST_LINKNODE ptListHead, PT_LIST_LINKNODE ptLinkNode)
{
    list_add_tail(ptListHead, ptLinkNode);
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

// judge stack has one list
E_BOOL_TYPE HasStackOneList(PT_LIST_LINKNODE ptStack)
{
    return ptStack->next->next == ptStack;
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

// push link node on stack 
PT_LIST_LINKNODE PushLinkNodeOnStack(PT_LIST_LINKNODE ptStack, PT_LIST_LINKNODE ptLinkNode)
{
    List_AddLink2Tail(ptStack, ptLinkNode);
}

// pop a link node from stack 
PT_LIST_LINKNODE PopLinkNodeFromStack(PT_LIST_LINKNODE ptStack)
{
    PT_LIST_LINKNODE ptLinkNode = NULL;
    
    if ( IsStackEmpty(ptStack) )
    {
        return NULL;
    }

    ptLinkNode = List_DetachLastLink(ptStack);

    return ptLinkNode;
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
                               MergeSort  function
************************************************************************/
PT_LIST_LINKNODE Merge_TwoList(PT_LIST_LINKNODE ptLinkNode_one, PT_LIST_LINKNODE ptLinkNode_two)
{
    PT_NODE_LISTHEAD ptNodeListHead_one = NULL;
    PT_NODE_LISTHEAD ptNodeListHead_two = NULL;
    PT_NODE_LISTHEAD ptNodeListHead_merged = NULL;

    PT_LIST_LINKNODE ptListHead_One = NULL;
    PT_LIST_LINKNODE ptListHead_Two = NULL;
    PT_LIST_LINKNODE ptListHead_merged = NULL;
    
    PT_NODE ptNodeOne = NULL;
    PT_NODE ptNodeTwo = NULL;
    
    E_BOOL_TYPE bIsListOneGo = TRUE;
    E_BOOL_TYPE bIsListTwoGo = TRUE;

    PT_LIST_LINKNODE ptLinkNode_merged = NULL;

    ptNodeListHead_merged = GetNode_ListHead();
    if ( !ptNodeListHead_merged )
    {
        return NULL;
    }
    ptListHead_merged = &(ptNodeListHead_merged->tListHead);

    ptNodeListHead_one = list_entry(ptLinkNode_one, T_NODE_LISTHEAD, tLinkNode);
    ptNodeListHead_two = list_entry(ptLinkNode_two, T_NODE_LISTHEAD, tLinkNode);

    ptListHead_One = &(ptNodeListHead_one->tListHead);
    ptListHead_Two = &(ptNodeListHead_two->tListHead);

    // merge list one and list two into a new list
    ptNodeOne = List_DetachFirstNode(ptListHead_One);
    ptNodeTwo = List_DetachFirstNode(ptListHead_Two);
    while( ptNodeOne && ptNodeTwo )
    {
        // node one is smaller
        if ( strcmp(ptNodeOne->str, ptNodeTwo->str) < 0 )
        {
            List_AddNode2Tail(ptListHead_merged, ptNodeOne);

            ptNodeOne = NULL;

            // list one shall get next node, list two keep current node
            bIsListOneGo = TRUE;
            bIsListTwoGo = FALSE;
        }
        // node two is smaller or equal
        else
        {
            List_AddNode2Tail(ptListHead_merged, ptNodeTwo);

            ptNodeTwo = NULL;

            // list one shall keep current node, list two shall get next node
            bIsListOneGo = FALSE;
            bIsListTwoGo = TRUE;
        }

        if ( bIsListOneGo )
        {
            ptNodeOne = List_DetachFirstNode(ptListHead_One);
        }

        if ( bIsListTwoGo )
        {
            ptNodeTwo = List_DetachFirstNode(ptListHead_Two);
        }
    }

    if ( ptNodeOne )
    {
        List_AddNode2Tail(ptListHead_merged, ptNodeOne);
        ptNodeOne = NULL;
    }

    if ( ptNodeTwo )
    {
        List_AddNode2Tail(ptListHead_merged, ptNodeTwo);
        ptNodeTwo = NULL;
    }

    // if list one has node yet, add them to merge list
    ptNodeOne = List_DetachFirstNode(ptListHead_One);
    while( ptNodeOne )
    {
        List_AddNode2Tail(ptListHead_merged, ptNodeOne);

        ptNodeOne = List_DetachFirstNode(ptListHead_One);
    }

    // if list two has node yet, add them to merge list
    ptNodeTwo = List_DetachFirstNode(ptListHead_Two);
    while( ptNodeTwo )
    {
        List_AddNode2Tail(ptListHead_merged, ptNodeTwo);

        ptNodeTwo = List_DetachFirstNode(ptListHead_Two);
    }

    FreeNode_ListHead(&ptNodeListHead_one);
    FreeNode_ListHead(&ptNodeListHead_two);

    ptLinkNode_merged = &(ptNodeListHead_merged->tLinkNode);
    
    return ptLinkNode_merged;
}

// execute one merge process, from left stack to right stack
void Merge_OneTime(PT_LIST_LINKNODE ptStackSrc, PT_LIST_LINKNODE ptStackDest)
{
    // execute two way merge
    PT_LIST_LINKNODE ptLinkNode_one = NULL;
    PT_LIST_LINKNODE ptLinkNode_two = NULL;
    PT_LIST_LINKNODE ptLinkNode_merged = NULL;

    while( !IsStackEmpty(ptStackSrc) )
    {
        ptLinkNode_one = PopLinkNodeFromStack(ptStackSrc);
        ptLinkNode_two = PopLinkNodeFromStack(ptStackSrc);

        // src stack has only one list, add to destine stack
        if ( !ptLinkNode_two )
        {
            PushLinkNodeOnStack(ptStackDest, ptLinkNode_one);
            break;
        }

        //src stack has two list yet, merge it, add merged list to destine stack
        ptLinkNode_merged = Merge_TwoList(ptLinkNode_one, ptLinkNode_two);
        
        PushLinkNodeOnStack(ptStackDest, ptLinkNode_merged);
    }
}

// src list head control real complete list, dest list head is only head, we use latter instand of former to control the list
void List_ReplaceHead(PT_LIST_LINKNODE ptListHead_src, PT_LIST_LINKNODE ptListHead_dest)
{
    PT_LIST_LINKNODE ptLinkNodeFirst = NULL;
    PT_LIST_LINKNODE ptLinkNodeLast = NULL;

    // if src list is empty, initialize dest head only
    if( IsListEmpty(ptListHead_src) )
    {
        INIT_LIST_HEAD(ptListHead_dest);
        
        return;
    }

    ptLinkNodeFirst = ptListHead_src->next;
    ptLinkNodeLast = ptListHead_src->prev;

    ptListHead_dest->next = ptLinkNodeFirst;
    ptLinkNodeFirst->prev = ptListHead_dest;
    ptListHead_dest->prev = ptLinkNodeLast;
    ptLinkNodeLast->next = ptListHead_dest;

    ptListHead_src->next = NULL;
    ptListHead_src->prev = NULL;
}

// make every node be a list and push the stack on stack
void MakeEveryNodeList2Stack(PT_LIST_LINKNODE ptListHead, PT_LIST_LINKNODE ptStack)
{
    PT_LIST_LINKNODE ptLinkNode = NULL;
    PT_LIST_LINKNODE ptNextCache = NULL;
    PT_NODE_LISTHEAD ptNodeListHead = NULL;

    // make all elements enter the left stack
    list_for_each_safe(ptListHead, ptLinkNode, ptNextCache)
    {
        // detatch this node from list
        list_del(ptLinkNode);

        ptNodeListHead = GetNode_ListHead();
        List_AddLink2Tail(&(ptNodeListHead->tListHead), ptLinkNode);

        // push new list on left stack 
        PushLinkNodeOnStack(ptStack, &(ptNodeListHead->tLinkNode));
    }
}

void PrintStackLists(PT_LIST_LINKNODE ptStack)
{
    PT_LIST_LINKNODE ptListHead = ptStack;
    PT_LIST_LINKNODE ptLinkNode = NULL;
    PT_NODE_LISTHEAD ptNodeListHead = NULL;
    PT_LIST_LINKNODE ptSubListHead = NULL;

    list_for_each(ptListHead, ptLinkNode)
    {
        ptNodeListHead = list_entry(ptLinkNode, T_NODE_LISTHEAD, tLinkNode);
        ptSubListHead = &(ptNodeListHead->tListHead);

        PrintList(ptSubListHead);
    }
}

void List_MergeSort(PT_LIST_LINKNODE ptListHead)
{
    // left stack for the even times of merging
    T_LIST_LINKNODE tStackLeft = {NULL, NULL};
    PT_LIST_LINKNODE ptStackLeft = &tStackLeft;

    // right stack for the odd times of merging    
    T_LIST_LINKNODE tStackRight = {NULL, NULL};
    PT_LIST_LINKNODE ptStackRight = &tStackRight;

    // final list may be in left stack or right stack, the final stack pointer is the result
    PT_LIST_LINKNODE ptStackFinal = NULL;

    PT_LIST_LINKNODE ptLinkNode_merged = NULL;
    PT_NODE_LISTHEAD ptNodeListHead_merged = NULL;
    PT_LIST_LINKNODE ptListHead_merged = NULL;

    INIT_LIST_HEAD(&tStackLeft);
    INIT_LIST_HEAD(&tStackRight);

    if ( IsListEmpty(ptListHead) )
    {
        return ;
    }

    MakeEveryNodeList2Stack(ptListHead, ptStackLeft);
    //PrintStackLists(ptStackLeft);

    while ( TRUE )
    {
        // merge the lists from left stack into right stack
        Merge_OneTime(ptStackLeft, ptStackRight);
        //PrintStackLists(ptStackLeft);
        //PrintStackLists(ptStackRight);        
        if ( HasStackOneList(ptStackRight) )
        {
            ptStackFinal = ptStackRight;
            break;
        }

        // merge the lists from right stack into left stack
        Merge_OneTime(ptStackRight, ptStackLeft);
        //PrintStackLists(ptStackLeft);
        //PrintStackLists(ptStackRight);     
        if ( HasStackOneList(ptStackLeft) )
        {
            ptStackFinal = ptStackLeft;
            break;
        }
    }

    // record merged final list into list head
    ptLinkNode_merged = PopLinkNodeFromStack(ptStackFinal);
    ptNodeListHead_merged = list_entry(ptLinkNode_merged, T_NODE_LISTHEAD, tLinkNode);
    ptListHead_merged = &(ptNodeListHead_merged->tListHead);

    List_ReplaceHead(ptListHead_merged, ptListHead);
    FreeNode_ListHead(&ptNodeListHead_merged);
}

void TestMergeSortCase()
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

    MyPrintf("----- now merge sort --------");
    
    List_MergeSort(&listHead);
    
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

   // test merge sort
  TestMergeSortCase();
    
    return 0;
}



