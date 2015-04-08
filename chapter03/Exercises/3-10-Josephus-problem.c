#include <stdio.h>
#include <stdlib.h>
#include "../circular-list.h"

void JosephusGame( List players , int m )
{
    Position P, TmpCell;
    int i;
    
    P = First( players );
    while( !IsEmpty( players ) )
    {
        for( i = 0; i < m; i++ )
        {
            P = Advance( P );
            if( IsHeader( P ) )
                P = Advance( P );
        }
        TmpCell = Advance( P );
        RemoveAndPrint( P, players );
        P = TmpCell;
    }
    printf( "\n" );
}

int main( void )
{
    List players;
    int i, m, n;

    m = 3;
    n = 15;
    players = MakeEmpty( NULL );
    for( i = 1; i <= n; i++ )
        InsertLast( i, players );

    JosephusGame( players, m );

    return 0;
}

