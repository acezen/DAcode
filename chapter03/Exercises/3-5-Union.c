#include <stdio.h>
#include <stdlib.h>
#include "../list.h"

List Union( List A, List B )
{
    List Ret;
    ElementType InsertElement;
    Position PtrToA, PtrToB, PtrToRet;

    PtrToA = First( A ); PtrToB = First( B );
    Ret = MakeEmpty( NULL );
    PtrToRet = Header( Ret );
    while( PtrToA != NULL && PtrToB != NULL )
    {
        if( PtrToA->Element < PtrToB->Element )
        {
            InsertElement = PtrToA->Element;
            PtrToA = Advance( PtrToA );
        }
        else if( PtrToA->Element > PtrToB->Element )
        {
            InsertElemnt = PtrToB->Element;
            PtrToB = Advance( PtrToB );
        }
        else
        {
            InsertElement = PtrToA->Element;
            PtrToA = Advance( PtrToA );
            PtrToB = Advance( PtrToB );
        }
        Insert( InsertElement, Ret, PtrToRet );
        PtrToRet = Advance( PtrToRet );
    }

    /* Flush out remaining list */
    while( PtrToA != NULL )
    {
        Insert( PtrToA->Element, Ret, PtrToRet );
        PtrToA = Advance( PtrToA );
        PtrToRet = Advance( PtrToRet );
    }
    while( PtrToB != NULL )
    {
        Insert( PtrToB->Element, Ret, PtrToRet );
        PtrToB = Advance( PtrToB );
        PtrToRet = Advance( PtrToRet );
    }

    return Ret;
}
    
