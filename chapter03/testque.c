#include <stdio.h>
#include "arrayQueue.h"

int main( void )
{
    Queue Q;
    int i;

    Q = CreateQueue(12);

    for( i = 0; i < 10; i++ )
        Enqueue( i, Q );

    while( !IsEmpty(Q) )
    {
        printf( "%d\n", Front(Q) );
        Dequeue( Q );
    }
    printf( "\n" );
    for( i = 0; i < 10; i += 2 )
        Enqueue( i, Q );
    while( !IsEmpty( Q ) )
    {
        printf( "%d\n", FrontAndDequeue( Q ) );
    }
    DisposeQueue( Q );
    return 0;
}

