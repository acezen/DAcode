#include <stdio.h>
#include <stdlib.h>
#include "adjusting-array.h"
#include "../fatal.h"

// 自适应表构造函数
adjustList CreateList( int MaxElements )
{
    adjustList L;

    if( MaxElements < MinListSize )
        Error( "List size is too small" );

    L = malloc( sizeof( struct arrayRecord ) );
    if( L == NULL )
        FatalError( "Out of space!!!" );

    L->Array = malloc( sizeof( ElementType ) * MaxElements );
    if( L->Array == NULL )
        FatalError( "Out of space!!!" );
    L->Capacity = MaxElements;
    MakeEmpty( L );

    return L;
}

void MakeEmpty( adjustList L )
{
    L->length = 0;
}

int IsEmpty( adjustList L )
{
    return L->length == 0;
}

int IsFull( adjustList L )
{
    return L->length == L->Capacity;
}

// 自适应表的插入，插入到表首
void Insert( ElementType X, adjustList L )
{
    if( IsFull( L ) )
        Error( "List is full" );
    else
    {
        int i;
        for( i = L->length; i > 0; i-- )   // 表内元素后移
            L->Array[i] = L->Array[i-1];
        L->Array[i] = X;
        L->length++;
    }
}

// the same as list
void Delete( ElementType X, adjustList L )
{
    int i;

    if( IsEmpty( L ) )
        Error( "Empty list" );
    i = 0;
    while( i < L->length && L->Array[i] != X )
        ++i;

    if( i == L->length )
        Error( "Not Found this Element" );
    else
    {
        for( ; i < L->length - 1; i++ )
            L->Array[i] = L->Array[i+1];
        L->length--;
    }
}

// 
void Find( ElementType X, adjustList L )
{
    Delete( X, L );
    Insert( X, L );
}

void PrintList( adjustList L )
{
    int i;

    for( i = 0; i < L->length; i++ )
        printf( "%d ", L->Array[i] );
    printf( "\n" );
}


// test example
int main( void )
{
    adjustList L;
    int i;

    L = CreateList( 15 );
    for( i = 0; i < 10; i++ )
        Insert( i, L );
    printf( "Orginary list: " );
    PrintList( L );

    printf( "Find element 5:\n" );
    Find( 5, L );
    PrintList( L );
    
    printf( "Find element 7:\n" );
    Find( 7, L );
    PrintList( L );

    printf( "Find element 1:\n" );
    Find( 1, L );
    PrintList( L );

    printf( "Delete element 3:\n" );
    Delete( 3, L );
    PrintList( L );

    printf( "Find element 3:\n" );
    Find( 3, L );
    PrintList( L );

    return 0;
}
