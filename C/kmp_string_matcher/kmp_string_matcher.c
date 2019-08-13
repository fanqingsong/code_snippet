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
    system("pause");
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



E_BOOL_TYPE string_is_head_of_string(char* headStr, char* string, int* pfailPos)
{
    char* pHeadStr = NULL;
    char* pString = NULL;
    char chHead = 0;
    char chString = 0;
    int index = 0;

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
            *pfailPos = index;
            return FALSE;
        }

        // headStr is not a head of string
        if ( chHead != chString )
        {
            *pfailPos = index;
            return FALSE;
        }

        pHeadStr++;
        pString++;

        index++;
    }
}

void calcPrefixlenByIndex(char* substr, int substrPrefix[], int iNum)
{
    int PrefixLen = 0;

MyPrintf("iNum = %d", iNum);

    if ( iNum == 0 )
    {
        substrPrefix[iNum] = 0;
    MyPrintf("iNum = %d substrPrefix[iNum]=%d", iNum, substrPrefix[iNum]);
        return;
    }

    // calc [0, iNum-1] string prefix len, saving to substrPrefix[iNum-1]
    calcPrefixlenByIndex(substr, substrPrefix, iNum-1);
    
    // according to [0, iNum-1] string prefix, we deduce [0, iNum] string prefix
    PrefixLen = substrPrefix[iNum-1];
    do
    {
        // if the char after the [0, iNum-1] string prefix is EQUAL to the char at substr[iNum],
        //  then the  the [0, iNum] string prefix len =  the [0, iNum-1] string prefix len + 1
        // PrefixLen+1-1 notation mean index from 0, while PrefixLen+1 mean index from 1
        if ( substr[PrefixLen+1-1] == substr[iNum] )
        {
            substrPrefix[iNum] = PrefixLen + 1;
            break;
        }
        // else calc from the prefix of the [0, iNum-1] string prefix
        else
        {
            PrefixLen = substrPrefix[PrefixLen];
        }        
    }while ( PrefixLen > 0 );

    MyPrintf("iNum = %d substrPrefix[iNum]=%d", iNum, substrPrefix[iNum]);
}

void compute_string_prefix(char* substr, int substrPrefix[], int maxPrefixEleNum)
{
    int substrlen = 0;

    substrlen = strlen(substr);
    if (substrlen > maxPrefixEleNum)
    {
        return;
    }

    calcPrefixlenByIndex(substr, substrPrefix, substrlen-1);
}

#define MAX_PREFIX_ELE_NUM 1024

int kmp_matcher(char* string, char* substr)
{
    char* cursor = NULL;
    int index = 0;
    int subLen = 0;
    int stringLen = 0;
    int maxPos = 0;

    int substrPrefix[MAX_PREFIX_ELE_NUM] = {0};
    int failPos = 0;
    int partialMatchedPos = 0;
    int maxPrefixLen = 0;

    // pointer to the inner postion of cursor and substr
    char* pCursor = NULL;
    char* pSubstr = NULL;

    if (!string || !substr)
    {
        MyPrintf("arg is null");
    }

    subLen = strlen(substr);
    stringLen = strlen(string);
    maxPos = stringLen - subLen + 1;

    // substrPrefix is string prefix of substr
    //  scope : 1-substrlen
    //  the index i element is the max prefix length of substr[1, i]
    compute_string_prefix(substr, substrPrefix, MAX_PREFIX_ELE_NUM); 

    index = 0;
    maxPrefixLen = 0;
    while ( index < maxPos )
    {
        cursor = string + index;

        pCursor = cursor + maxPrefixLen;
        pSubstr = substr + maxPrefixLen;
        
        if ( string_is_head_of_string(pSubstr, pCursor, &failPos) )
        {
            return index;
        }
        else
        {
            // failPos scope: 0-substrlen-1
            // failPos is substr comparing char postion that do not match cursor string
            // then substr[0, partialMatchedPos] is the matched part
            partialMatchedPos = maxPrefixLen + failPos - 1;

            // substr[0] is not matched
            if ( failPos == 0 )
            {
                // string compare from next position
                index ++;

                // next comparation have not to consider prefix
                maxPrefixLen = 0;
            }
            else
            {
                // the max prefix length of partial matched string, ie substr[0, partialMatchedPos]
                maxPrefixLen = substrPrefix[partialMatchedPos];
                
                index += partialMatchedPos - maxPrefixLen;
            }
        }
    }

    return -1;
}

int main(void)
{
    char string[] = "i aba you";
    char substr[] = "aba";
    int index = -1;

    index = kmp_matcher(string, substr);

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
