#include <stdio.h>
#include <stdlib.h>
#include "../list.h"

typedef PtrToNode Polynomial;


Polynomial AddPoly( const Polynomial Poly1, const Polynomial Poly2 )
{
    Polynomial Ret;
    PtrToNode Ptr1, Ptr2, PtrRet;

    Ret = MakeEmpty( NULL );
    Ptr1 = First( Poly1 ); Ptr2 = First( Poly2 );
    PtrRet = Header( Ret );

    while( Ptr1 != NULL && Ptr2 != NULL )
    {
        if( Ptr1->Exponent < Ptr2->Exponent )
        {
            InsertPoly( Ptr1->Exponent, Ptr1->Coefficient, Ret, PtrRet );
            Ptr1 = Advance( Ptr1 );
            PtrRet = Advance( PtrRet );
        }
        else if( Ptr1->Exponent > Ptr2->Exponent )
        {
            InsertPoly( Ptr2->Exponent, Ptr2->Coefficient, Ret, PtrRet );
            Ptr2 = Advance( Ptr2 );
            PtrRet = Advance( PtrRet );
        }
        else
        {
            InsertPoly( Ptr1->Exponent, Ptr1->Coefficient+Ptr2->Coefficient, Ret, PtrRet );
            Ptr1 = Advance( Ptr1 );
            Ptr2 = Advance( Ptr2 );
            PtrRet = Advance( PtrRet );
        }
    }

    /* fulash remaining list */
    while( Ptr1 != NULL )
    {
            InsertPoly( Ptr1->Exponent, Ptr1->Coefficient, Ret, PtrRet );
            Ptr1 = Advance( Ptr1 );
            PtrRet = Advance( PtrRet );
    }
    while( Ptr2 != NULL )
    {
            InsertPoly( Ptr2->Exponent, Ptr2->Coefficient, Ret, PtrRet );
            Ptr2 = Advance( Ptr2 );
            PtrRet = Advance( PtrRet );
    }

    return Ret;
}

// test
int main( void )
{
    Polynomial Poly1, Poly2;
    PtrToNode P;
    int i;

    Poly1 = MakeEmpty( NULL );
    Poly2 = MakeEmpty( NULL );
    
    P = Header( Poly1 );
    for( i = 0; i < 10; i++ )
    {
        InsertPoly( i, 2*i + 1, Poly1, P );
        P = Advance( P );
    }
    PrintList( Poly1 );

    P = Header( Poly2 );
    for( i = 0; i < 10; i += 2)
    {
        InsertPoly( i, 2*i, Poly2, P );
        P = Advance( P );
    }
    PrintList( Poly2 );

    Polynomial Poly;
    Poly = MakeEmpty( NULL );
    Poly = AddPoly( Poly1, Poly2 );
    PrintList( Poly );

    return 0;
}

