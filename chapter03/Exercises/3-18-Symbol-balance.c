#include <stdio.h>
#include <stdlib.h>

// 可选择数组实现的栈获链表实现的栈
/* #include "../arrayStack.h */
#include "../listStack.h"

#define TRUE (1)
#define FALSE (0)

int IsBalance( ElementType *Symbols )
{
    Stack S;
    int i;
    char record, oprecord;
    char record2, oprecord2;    // for '\*', '*/' symbols;
    S = CreateStack();

    // check
    while( Symbols[i] != '\0' )
    {
        record = Symbols[i];    // 读取当前字符
        switch( record )        
        {
            case '(':           // 若为左符号则压栈
            case '[':
            case '{':
                Push( record, S );
                break;
            case '\\':           // 特殊的'\*'
                record2 = Symbols[++i];
                if( record2 != '*' )
                {
                    return FALSE;
                }
                Push( record, S );
                Push( record2, S );
                break;
            case ')':           // 若为右符号则出栈并比对
                if( IsEmpty( S ) )
                {
                    printf( "unvalid expression!\n" );
                    return FALSE;
                }
                oprecord = TopAndPop( S );
                if( oprecord != '(' )
                    return FALSE;
                break;
            case ']':
                if( IsEmpty( S ) )
                {
                    printf( "unvalid expression!\n" );
                    return FALSE;
                }
                oprecord = TopAndPop( S );
                if( oprecord != '[' )
                    return FALSE;
                break;
            case '}':
                if( IsEmpty( S ) )
                {
                    printf( "unvalid expression!\n" );
                    return FALSE;
                }
                oprecord = TopAndPop( S );
                if( oprecord != '{' )
                    return FALSE;
                break;
            case '*':           // 特殊的'*/'
                if( IsEmpty( S ) )
                {
                    printf( "unvalid expression!\n" );
                    return FALSE;
                }
                record2 = Symbols[++i];
                oprecord = TopAndPop( S );
                oprecord2 = TopAndPop( S );
                if( record2 != '/' || oprecord != '*' || oprecord2 != '\\' )
                    return FALSE;
                break;
            default:
                printf( "Unvalid symbol!\n" );
                return FALSE;
        }
        
        i++;
    }

    if( !IsEmpty( S ) )     
        return FALSE;   // 栈不空，不平衡
    return TRUE;
}
                
// test
int main(void)
{
    char *symbols = "\\**/(){}[]}";

    if( IsBalance( symbols ) )
        printf( "The symbol is balance\n");
    else
        printf( "the symbols is not balance\n" );

    return 0;
}
