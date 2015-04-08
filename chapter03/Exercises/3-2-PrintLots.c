#include <stdio.h>
#include <stdlib.h>
#include "../list.h"

ElementType GetElem( ElementType n, List L )
{
    ElementType i;
    Position Tmp = L;
    for( i = 0; i < n; i++ )
    {
        Tmp = Tmp->Next;
        if( Tmp == NULL )
        {
            printf( "Error: there is no %dth element\n", n );
            exit( 1 );
        }
    }

    return Tmp->Element;
}

void PrintLots( List L, List P )
{
    if( IsEmpty( P ) )
        printf( "No element have to print\n" );
    else
    {
        Position Tmp = P->Next;
        do
        {
            printf("%d ", GetElem( Tmp->Element, L ) );
            Tmp = Tmp->Next;
        } while( Tmp != NULL );
    }
    printf( "\n" );
}

int main( void )
{
    List L, P;
    int i;

    L = MakeEmpty( NULL );
    P = MakeEmpty( NULL );

    Position Tmp = Header( L );
    for( i = 0; i < 10; i++ )
    {
        Insert( i, L, Tmp );
        Tmp = Advance( Tmp );
    }

    Tmp = Header( P );
    for( i = 1; i < 10; i += 2 )
    {
        Insert( i, P, Tmp );
        Tmp = Advance( Tmp );
    }

    PrintLots( L, P );

    return 0;
}
