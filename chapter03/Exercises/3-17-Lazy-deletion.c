#include <stdio.h>
#include <stdlib.h>
#include "../list.h"

struct Node
{
    ElementType ELement;
    int DelFlag;
    PtrToNode   Next;
};

struct ListRecord
{
    int Length;
    int DelCount;
    PtrToNode   Header;
};
typedef ListRecord *List;

void LazyDelete( ElementType X, List L )
{
    Position P;

    P = First( L );
    while( P != NULL )
        P = Advance( P );
    
    if( P == NULL )
        Error( "Not found the element" );
    else
    {
        P->DelFlag = TURE;
        L->DelCount--;
    }

    if( L->DelCount == L->Length / 2 )
        DeleteAllFlag( L );
}

void DeleteAllFlag( List L )
{
    Position P;

    P = First( L );
    while( P != NULL )
    {
        if( P->DelFlag == TRUE )
        {
            TmpCell = Advance( P );
            DeletePtr( P, L );
            P = TmpCell;
        }
        else
            P = Advance( P );
    }
    L->DelCount = 0;
    L->Length = L->Length / 2;
}

