#include <stdlib.h>
#include <stdio.h>
#include "list.h"
/*
struct Node
{
    ElementType Element;
    Position    Next;
};
*/

void InsertPoly( int Exponent, int Coefficient, Polynomial P, Position Ptr )
{
    Position TmpCell;

    TmpCell = malloc( sizeof( struct Node ) );
    if( TmpCell == NULL )
    {
        printf("Out of space!" );
        exit(1);
    }

    TmpCell->Exponent = Exponent;
    TmpCell->Coefficient = Coefficient;
    TmpCell->Next = Ptr->Next;
    Ptr->Next = TmpCell;
}
/* Create an empty list, return the ptr to the header */
List MakeEmpty( List L )
{
    List TmpList;
    TmpList = malloc( ( sizeof( struct Node ) ) );
    TmpList->Next = NULL;

    return TmpList;
}

/* Return true if list is empty */
int IsEmpty( List L )
{
    return L->Next == NULL;
}

/* return true if P is the last position in list L */
int IsLast( Position P, List L )
{
    return P->Next == NULL;
}

/* Return position of X in L; NULL if not found 
Position Find( ElementType X, List L )
{
    Position P;

    P = L->Next;
    while( P != NULL && P->Element != X )
        P = P->Next;

    return P;
} */

/* Return the previous position of X in L;
 * if X if not found, then return filed of returned: NULL
 * Assumes a header 
Position FindPrevious( ElementType X, List L )
{
    Position P;

    P = L;
    while( P->Next != NULL && P->Next->Element != X )
        P = P->Next;

    return P;
} */

/* Delete first occurrence of X from L;
  Assume a header used *
void Delete( ElementType X, List L )
{
    Position Pre;

    Pre = FindPrevious( X, L );
    if( !IsLast( Pre, L ) )
    {
        Position TmpCell = Pre->Next;
        Pre->Next = TmpCell->Next;
        free( TmpCell );
    }
} */

/* Insert X to List after the Position P
void Insert( ElementType X, List L, Position P )
{
    Position TmpCell;
    
    TmpCell = malloc( sizeof( struct Node ) );
    if( !TmpCell )
    {
        printf( "Out of Space!" );
        exit(1);
    }

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
} */

void DeleteList( List L )
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

Position Header( List L )
{
    return L;
}

Position First( List L )
{
    return L->Next;
}

Position Advance( Position P )
{
    return P->Next;
}
/*
ElementType Retrieve( Position P )
{
    return P->Element;
} */

void PrintList( const List L )
{
    Position P = Header( L );

    if ( IsEmpty( L ) )
        printf( "Empty list\n" );
    else
    {
        do
        {
            P = Advance( P );
/*            printf( "%d ", Retrieve( P ) );    */
            printf( "%d-%d ", P->Coefficient, P->Exponent );
        } while ( !IsLast( P, L ) );
        printf( "\n" );
    }
}
