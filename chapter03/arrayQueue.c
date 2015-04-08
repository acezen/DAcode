#include <stdio.h>
#include <stdlib.h>
#include "arrayQueue.h"
#include "fatal.h"

#define MinQueueSize ( 5 )
#define MaxElements (50)
struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

int IsEmpty( Queue Q )
{
    return Q->Size == 0;
}

int IsFull( Queue Q )
{
    return Q->Size == Q->Capacity;
}

Queue CreateQueue(void)
{
    Queue Q;

    if( MaxElements < MinQueueSize )
        Error( "Queue size is too small" );

    Q = malloc( sizeof( struct QueueRecord ) );
    if( Q == NULL )
        FatalError( "Out of space!!!" );
    
    Q->Array = malloc( sizeof( ElementType ) * MaxElements );
    if( Q->Array == NULL )
        FatalError( "Out of space!!!" );
    Q->Capacity = MaxElements;
    MakeEmpty( Q );

    return Q;
}

void MakeEmpty( Queue Q )
{
    Q->Front =0;
    Q->Rear = -1;
    Q->Size = 0;
}

void DisposeQueue( Queue Q )
{
    if( Q != NULL )
    {
        free( Q->Array );
        free( Q );
    }
}

static int Succ( int Value, Queue Q )
{
    if( ++Value == Q->Capacity )
        Value = 0;
    return Value;
}

void Enqueue( ElementType X, Queue Q )
{
    if( IsFull ( Q ) )
        Error( "Full Queue" );
    else
    {
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[ Q->Rear ] = X;
        Q->Size++;
    }
}

void Dequeue( Queue Q )
{
    if( IsEmpty( Q ) )
        Error( "Empty Queue" );
    else
    {
        Q->Front = Succ(Q->Front, Q);
        Q->Size--;
    }
}

ElementType Front( Queue Q )
{
    if( IsEmpty( Q ) )
    {
        Error( "Empty Queue" );
        return 0;
    }
    else
        return Q->Array[ Q->Front ];
}

ElementType FrontAndDequeue( Queue Q )
{
    if( IsEmpty( Q ) )
    {
        Error( "Empty queue" );
        return 0;
    }
    else
    {
        ElementType Tmp = Q->Array[ Q->Front ];
        Q->Front = Succ(Q->Front, Q);
        Q->Size--;
        return Tmp;
    }
}

