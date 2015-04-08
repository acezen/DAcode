#include "Binary-search-tree.h"
#include <stdio.h>

int main()
{
    SearchTree T;
    Position P;
    
    T = MakeEmpty( NULL );
    for( int i = 0, int j = 0; i < 50; i++, j = ( j + 7 ) % 50 )
        T = Insert( j, T );
    for( int i = 0; i < 50; i++ )
        if( (P = FInd( i, T )) == NULL || Retrieve( P ) != i )
            printf( "Error at %d\n", i );

    for( int i = 0; i < 50; i += 2 )
        T = Delete( i, T );

    for( int i = 1; i < 50; i += 2 )
        if( (P = FInd( i, T )) == NULL || Retrieve( P ) != i )
            printf( "Error at %d\n", i );

    for( int i = 0; i < 50; i += 2 )
        if( (P = FInd( i, T )) == NULL )
            printf( "Error at %d\n", i );

    printf( "Min is %d, Max if %d\n", Retrieve( FindMin( T ) ), Retrieve( FindMax( T ) ) );

    return 0;
}
            
