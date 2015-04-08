#include <stdio.h>
#include "adjust-linkedlist.h"

// test example
int main( void )
{
    adjustList L;
    int i;

    L = CreateList( NULL );
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
