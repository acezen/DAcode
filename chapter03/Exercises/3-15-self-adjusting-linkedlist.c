/*
 * 自适应表的链表实现，
 * 除 Insert函数和Find函数外，其他函数与链表类似
 */

#include <stdio.h>
#include <stdlib.h>
#include "adjust-linkedlist.h"
#include "../fatal.h"

adjustList CreateList( adjustList L )
{
    if( L != NULL )
        DeleteList( L );

    L = malloc( sizeof( struct Node ) );
    if( L == NULL )
        FatalError( "Out of space!!!" );

    L->Next = NULL;

    return L;
}
    
int IsEmpty( adjustList L )
{
    return L->Next == NULL;
}

/* return true if P is the last position in list L */
int IsLast( Position P, adjustList L )
{
    return P->Next == NULL;
}
   
void Insert( ElementType X, adjustList L )
{
    Position TmpCell;

    TmpCell = malloc( sizeof( struct Node ) );
    if( TmpCell == NULL )
        FatalError( "Out of space!!!" );
    
    // 插入表头
    TmpCell->Element = X;
    TmpCell->Next = L->Next;
    L->Next = TmpCell;
}

void Delete( ElementType X, adjustList L )
{
    Position Pre;

    Pre = FindPrevious( X, L );
    if( !IsLast( Pre, L ) )
    {
        Position TmpCell = Pre->Next;
        Pre->Next = TmpCell->Next;
        free( TmpCell );
    }
}

void DeleteList( adjustList L )
{
    Position P, TmpCell;

    P = L->Next;
    L->Next = NULL;
    while( P != NULL )
    {
        TmpCell = P->Next;
        free( P );
        P = TmpCell;
    }
}

Position FindPrevious( ElementType X, adjustList L )
{
    Position P;

    P = L;
    while( P->Next != NULL && P->Next->Element != X )
        P = P->Next;

    return P;
} 

void Find( ElementType X, adjustList L )
{
    Position Pre, P;

    Pre = FindPrevious( X, L );
    if( Pre->Next == NULL )
        Error( "Not found element" );
    else
    {
        P = Pre->Next;

        // Delete
        Pre->Next = P->Next;
        // 插入表头
        P->Next = L->Next;
        L->Next = P;
    }
}

Position Header( adjustList L )
{
    return L;
}

Position First( adjustList L )
{
    return L->Next;
}

Position Advance( Position P )
{
    return P->Next;
}

ElementType Retrieve( Position P )
{
    return P->Element;
}

void PrintList( const adjustList L )
{
    Position P = Header( L );

    if ( IsEmpty( L ) )
        printf( "Empty list\n" );
    else
    {
        do
        {
            P = Advance( P );
            printf( "%d ", Retrieve( P ) );    
        } while ( !IsLast( P, L ) );
        printf( "\n" );
    }
}
