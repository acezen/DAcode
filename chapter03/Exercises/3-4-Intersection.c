#include <stdlib.h>
#include <stdio.h>
#include "../list.h"

List Intersection( List A, List B )
{
    List Ret;
    Position PtrToA, PtrToB, PtrToRet;

    Ret = MakeEmpty( NULL );
    PtrToA = First( A );
    PtrToB = Header( B );
    PtrToRet = Header( Ret );

    while( PtrToA != NULL )
    {
        while( Advance( PtrToB ) != NULL )
        {
            if( PtrToA->Element == PtrToB->Next->Element )
            {
                Insert( PtrToA->Element, Ret, PtrToRet );
                PreToRet = Advance( PtrToRet );
                break;
            }
            else if( PtrToA->Element < PtrToB->Next->Element )
                break;
            
            PtrToB = Advance( PtrToB );
        }

        if( Advance( PtrToB ) == NULL )
            break;

        PtrToA = Advance( PtrToA );
    }

    return Ret;
}
