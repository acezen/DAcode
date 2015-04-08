/****************************************
 * This is an implementation of circular
 * linked list with header.
 * We assume that other node's data are
 * all nonnegative, so the header has a
 * sentinel -1
 */

#include <stdio.h>
#include <stdlib.h>
#include "circular-list.h"
#include "fatal.h"

struct Node 
{
    ElementType Element;
    PtrToNode   Next;
};

List MakeEmpty( List L )
{
    if( L != NULL )
        DeleteList( L );
    L = malloc( sizeof( struct Node ) );
    if( L == NULL )
        FatalError( "Out of space" );
    L->Element = -1;
    L->Next = L;

    return L;
}

int IsEmpty( List L )
{
    return L->Next == L;
}

int IsHeader( Position P)
{
    return P->Element == -1;
}

int IsLast( Position P, List L )
{
    return P->Next == L;
}

void RemoveAndPrint( Position P, List L )
{
    Position Pre;
    
    Pre = FindPrevious( P, L );
    Pre->Next = P->Next;
    printf( "%d ", P->Element );
    free( P );
}

void InsertLast( ElementType X, List L )
{
    Position P, TmpCell;

    P = L;
    while( !IsLast( P, L ) )
        P = Advance( P );

    TmpCell = malloc( sizeof( struct Node ) );
    if( TmpCell == NULL )
        FatalError( "Out of space!!!" );

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

Position FindPrevious( Position P, List L )
{
    Position Pre;
   
    if( IsEmpty( L ) )
        Error( "Empty list" );

    Pre = L;
    while( Pre->Next != P )
        Pre = Pre->Next;

    return Pre;
}

void DeleteList( List L )
{
    Position P, TmpCell;
    
    P = L->Next;
    L->Next = L;
    while( P != L )
    {
        TmpCell = P->Next;
        free( P );
        P = TmpCell;
    }
        
}

Position Advance( Position P )
{
    return P->Next;
}

Position Header( List L )
{
    return L;
}

Position First( List L )
{
    return L->Next;
}

ElementType Retrieve( Position P )
{
    return P->Element;
}
