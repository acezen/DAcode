#include <stdio.h>
#include <stdlib.h>
#include "../list.h"

// 3-12a, 利用头插法逆转链表
void ReverseList( List L )
{
    Position P, TmpCell;

    P = First( L );
    L->Next = NULL;
    while( P != NULL )
    {
        TmpCell = P->Next;
        P->Next = L->Next;
        L->Next = P;
        P = TmpCell;
    }
}

// 3-12b, assuming a header and L is not empty
void ReverseList2( List L )
{
    Position CurrentPos, NextPos, PreviousPos;

    PreviousPos = NULL;
    CurrentPos = L->Next;
    NextPos = CurrentPos->Next;
    while( NextPos != NULL )
    {
        CurrentPos->Next = PreviousPos;
        PreviousPos = CurrentPos;
        CurrentPos = NextPos;
        NextPos = NextPos->Next;
    }
    CurrentPos->Next = PreviousPos;
    L->Next = CurrentPos;
}

int main( void )
{
    List L;
    Position P;
    int i;

    L = MakeEmpty( NULL );
    P = Header( L );
    for( i = 0; i < 10; i++ )
    {
        Insert( i, L, P );
        P = Advance( P );
    }
    PrintList( L );

    ReverseList2( L );
    PrintList( L );

    return 0;
}
