/* 后缀表达式计算的实现
 * 该例程只能实现数字及结果都<10的整数的计算
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// 可选的栈实现头文件
//#include "../arrayStack.h"
#include "../listStack.h"

int PostfixCal( ElementType *Expression )
{
    int ret;
    Stack S;
    char record, num1, num2, result;
    int i;

    ret = 0;
    S = CreateStack();
    i = 0;
    while( Expression[i] != '\0' )
    {
        record = Expression[i];
        if( isdigit(record) )
            Push( record, S );
        else
        {
            switch( record )
            {
                case '+':
                    num1 = TopAndPop( S ) - '0';
                    num2 = TopAndPop( S ) - '0';
                    result = (num1 + num2) + '0';
                    Push( result, S );
                    break;
                case '-':
                    num1 = TopAndPop( S ) - '0';
                    num2 = TopAndPop( S ) - '0';
                    result = (num1 - num2) + '0';
                    Push( result, S );
                    break;
                case '*':
                    num1 = TopAndPop( S ) - '0';
                    num2 = TopAndPop( S ) - '0';
                    result = (num1 * num2) + '0';
                    Push( result, S );
                    break;
                case '/':
                    num1 = TopAndPop( S ) - '0';
                    num2 = TopAndPop( S ) - '0';
                    result = (num1 / num2) + '0';
                    Push( result, S );
                    break;
                default:
                    printf( "unvalid expression" );
                    exit(1);
            }
        }
        i++;
    }

    ret = TopAndPop( S ) - '0';
    if( !IsEmpty( S ) )
    {
        printf( "unvalid expression\n" );
        exit(1);
    }

    return ret;
}


// test
int main(void)
{
    char *expression = "11+2+1+1+1+1+";

    int ret;
    ret = PostfixCal( expression );
    printf( "The result is %d\n", ret );

    return 0;
}
