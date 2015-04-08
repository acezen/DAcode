/* 中缀表达式转化为后缀表达式的算法实现
 * 后缀表达式存放在队列中
 *********************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../arrayStack.h"  // Optional stack implementation
//#include "../listStack.h"
//#include "../arrayQueue.h"

void InfixToPostfix( ElementType *Expression )
{
    Stack S;
    //Queue Q;
    ElementType record, pop_record;
    int i;

    S = CreateStack();
    //Q = CreateQueue();
    i = 0;
    while( Expression[i] != '\0' )
    {
        record = Expression[i];
        if( isalnum( record ) )
            //EnQueue( record, Q );   // 若为数字，直接入队  
            printf( "%c", record );
        else
        {
            switch( record )
            {
                case '(':
                    Push( record, S );
                    break;
                case ')':
                    while( Top( S ) != '(' )
                    {
                        pop_record = TopAndPop( S );
                        printf( "%c", pop_record );
                        //EnQueue( pop_record, Q );
                    }
                    Pop( S );   // '('出栈但不入队
                    break;
                case '+':
                case '-':
                    while( !IsEmpty( S ) && Top( S ) != '(' )
                    {
                        pop_record = TopAndPop( S );
                        printf( "%c", pop_record );
                        //EnQueue( pop_record, Q );
                    }
                    Push( record, S );
                    break;
                case '*':
                case '/':
                    while( !IsEmpty(S) && Top(S) != '(' && Top(S) != '+'
                            && Top(S) != '-' )
                    {
                        pop_record = TopAndPop( S );
                        printf( "%c", pop_record );
                    }
                    Push( record, S );
                    break;
                case '^':
                    while( !IsEmpty(S) && Top(S) == '^' )
                        printf( "%c", TopAndPop(S) );
                    Push( record, S );
                    break;
                default:
                    printf( "Unvalid Expression!\n" );
            }
        }

        i++;
    }
    while( !IsEmpty( S ) )
        printf( "%c", TopAndPop( S ) );
    printf( "\n" );
}
                
// test
int main(void)
{
    char *expression = "a+b*c+(d*e+f)^g";

    InfixToPostfix( expression );

    return 0;
}
