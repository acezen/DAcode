// 一个数组实现两个栈的例程

#include <stdio.h>
#include <stdbool.h>

#define MaxElements 100
int leftTop = 0;
int rightTop = 99;

DoubleStack MakeEmpty( void )
{
    ElementType S[MaxElements];
    leftTop = 0;
    rightTop = MaxElements - 1;

    return S;
}

bool IsLeftEmpty( DoubleStack S )
{
    return leftTop == 0;
}

bool IsRightEmpty( DoubleStack S )
{
    return rightTop == MaxElements-1;
}

bool IsFull( DoubleStack S )
{
    return leftTop == rightTop-1;
}

void PushLeft( ElmentType X, DoubleStack S )
{
    if( IsFull( S ) )
        Error( "Stack is full" );
    else
        S[ leftTop++ ] = X;
}

void PushRight( ElementType X, DoubleStack S )
{
    if( IsFull( S ) )
        Error( "Stack is full" );
    else
        S[ rightTop-- ] = X;
}

ElementType PopLeft( DoubleStack S )
{
    if( IsLeftEmpty( S ) )
        Error( "The left stack is empty" );
    else
        return S[ --leftTop ];
}

ElementType PopRight( DoubleStack S )
{
    if( IsRightEmpty( S ) )
        Error( "The right stack is empty" );
    else 
        return S[ ++rightTop ];
}

    
}

