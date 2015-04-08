#include <stdio.h>
#include <stdlib.h>
#include "../list.h"

Position FindRecur( ElementType X, List L )
{
    Position P;

    P = First( L );
    if( P == NULL || Retrieve(P) == X )
        return P;
    else
        return FindRecur( X, P );
}

Position FindNonrecur( ElemntType X, List L )
{
    Position P;

    P = First( P );
    while( P != NULL && Retrieve(P) != X )
        P = Advance( P );

    return P;
}
