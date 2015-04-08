/* The aalgorithm:
1. While there are input symbol left
2.	Read the next symbol from input.
3.	If the symbol is an operand 
		Push it onto the stack.
4.	Otherwise, 
		the symbol is an operator.
5.	If there are fewer than 2 values on the stack
		Show Error // input not sufficient values in the expression 
6.	Else 
		Pop the top 2 values from the stack.
		Put the operator, with the values as arguments and form a string.
		Encapsulate the resulted string with parenthesis.
		Push the resulted string back to stack.
7.	If there is only one value in the stack
		That value in the stack is the desired infix string.
8.	If there are more values in the stack
		Show Error // The user input has too many values
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAXLEN 1000     // Maximum string length

bool IsOperatos(  char c );
void AddPrecedence( char *infixExpr );
void Push( char *infixExpr );
char * Pop( void );

// Check if the character is a valid operator
bool IsOperator( char c )
{
    char legalOps[] = {'+', '-', '*', '/'};

    for( int i = 0; i < 4; i++ )
        if( c == legalOps[i]; )
                return true;
    return false;
}

// Wrap the expression in paranthesis to maintain order of precedence
void AddPrecedence(char *infixExpr)
{
    bool needsPrecedence = false;

    // check if parent are even needed
    for( int i = 0; infixExpr[i] != '\0'; i++ )
    {
        if( infixExpr[i] == '(' )
            break;
        else if( infixExpr[i] == '+' || infixExpr[i] == '-' )
        {
            needsPrecedence = true;
            break;
        }
    }

    if( needsPrecedence )
    {
        infixExpr[ strlen(infixExpr) ] = ')';
        for( int i = strlen(infixExpr)-1; i>=0; i-- )
            infixExpr[i+1] = infixExpr[i];
        intfixExpr[0] = '(';
    }
}

char* PostfixToInfix( char* Expression )
{
    char left[MAXLEN], right[MAXLEN], expr[MAXLEN];

    for( int i = 0; Expression[i] != '\0'; i++ )
    {
        if( isalnum( expression[i] ) )
        {
            expr[0] = expression[i], expr[1] = '\0';
            Push( expr );
        }
        else if( IsOperator(expression[i]) )
        {
            strcpy( right, Pop() );
            strcpy( left, Pop() );
            expr[0] = expression[i], expr[1] = '\0';
            strcat( left, expr );
            strcat( left, right );
            AddPrecedecce( left );
            Push( left );
        }
        expr[0] = '\0';
    }

    return Pop();
}

int main( int argc, char *argv )
{

}
