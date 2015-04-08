#include <stdio.h>
#include <stdlib.h>
#include "arrayStack.h"
#include "fatal.h"

#define EmptyTOS ( -1 )
#define MinStackSize ( 5 )
#define MaxElements (50)    // 为了与listStack的实现同步
struct StackRecord
{
    int Capacity;
    int Top;
    ElementType *Array;
};

int IsEmpty( Stack S )
{
    return S->Top == -1;
}

int IsFull( Stack S )
{
    return S->Top == S->Capacity + EmptyTOS;
}

Stack CreateStack(void)
{
    Stack S;
    
    if( MaxElements < MinStackSize )
        Error( "Stack size is too small" );

    S = malloc( sizeof( struct StackRecord ) );
    if( S == NULL )
        FatalError( "Out of space!!!" );

    S->Array = malloc( sizeof( ElementType ) * MaxElements );
    if( S->Array == NULL )
        FatalError( "Out of space!!!" );
    S->Capacity = MaxElements;
    MakeEmpty( S );

    return S;
}

void MakeEmpty( Stack S )
{
    S->Top = EmptyTOS;
}

void DisposeStack( Stack S )
{
    if( S != NULL )
    {
        free( S->Array );
        free( S );
    }
}

void Push( ElementType X, Stack S )
{
    if( IsFull( S ) )
        Error( "The Stack is full" );
    else
        S->Array[ ++S->Top ] = X;
}

void Pop( Stack S )
{
    if( IsEmpty( S ) )
        Error( "Empty Stack" );
    else
        S->Top--;
}

ElementType Top( Stack S )
{
    if( IsEmpty( S ) )
    {
        Error( "Empty stack" );
        return 0;
    }
    else
        return S->Array[ S->Top ];
}

ElementType TopAndPop( Stack S )
{
    if( !IsEmpty( S ) )
        return S->Array[ S->Top-- ];
    Error( "Empty stack" );
    return 0;
}
