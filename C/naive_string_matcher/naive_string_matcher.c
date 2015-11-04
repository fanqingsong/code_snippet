#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>
#include <stdarg.h>
#include <ctype.h>


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

E_BOOL_TYPE string_is_head_of_string(char* headStr, char* string)
{
    char* pHeadStr = NULL;
    char* pString = NULL;
    char chHead = 0;
    char chString = 0;

    if (!headStr || !string)
    {
        MyPrintf("arg is null");
        return FALSE;
    }

    pHeadStr = headStr;
    pString = string;

    while( TRUE )
    {
        chHead = *pHeadStr;
        chString = *pString;

        // headStr is over, now result is true
        if ( chHead == 0 )
        {
            return TRUE;
        }

        // string is over firstly, return false 
        if ( chString == 0 )
        {
            return FALSE;
        }

        // headStr is not a head of string
        if ( chHead != chString )
        {
            return FALSE;
        }

        pHeadStr++;
        pString++;
    }
}

int naive_matcher(char* string, char* substr)
{
    char* cursor = NULL;
    int index = 0;
    int subLen = 0;
    int stringLen = 0;
    int maxPos = 0;

    if (!string || !substr)
    {
        MyPrintf("arg is null");
    }

    subLen = strlen(substr);
    stringLen = strlen(string);
    maxPos = stringLen - subLen + 1;

    while ( index < maxPos )
    {
        cursor = string + index;
        if ( string_is_head_of_string(substr, cursor) )
        {
            return index;
        }
        
        index++;
    }

    return -1;
}

int main(void)
{
    char string[] = "i love you";
    char substr[] = "love";
    int index = -1;

    index = naive_matcher(string, substr);

    if ( -1 == index )
    {
        MyPrintf("substr(%s) is not in string(%s)", substr, string);
    }
    else
    {
        MyPrintf("substr(%s) is at index(%d) of string(%s)", substr, index, string);
    }
    
    return 0; 
}
