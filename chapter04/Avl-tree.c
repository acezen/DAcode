#include <stdio.h>
#include <stdlib.h>
#include "Avl-tree.h"

static int Height( Position P )
{
    if( P == NULL )
        return -1;
    else
        return P->Height;
}

Position Find( ElementType X, AvlTree T )
{
    if( T == NULL )
        return NULL;
    if( X < T->Element )
        return Find( X, T->Left );
    else if( X > T->Element )
        return Find( X, T->Right );
    else
        return T;
}

Position FindMin( AvlTree T )
{
    if( T == NULL )
        return NULL;
    else if( T->Left == NULL )
        return T;
    else
        return FindMin( T->Left );
}

Position FindMax( AvlTree T )
{
    if( T != NULL )
        while( T->Right != NULL )
            T = T->Right;
    return T;
}

AvlTree Insert( ElementType X,  AvlTree T )
{
    if( T == NULL )
    {
        // Create and return a one-node tree
    }
    else if( X < T->Element )
    {
        T->Left = Insert( X, T->Left );
        if( Height( T->Left ) - Height( T->Right ) == 2 )
            if( X < T->Left->Element )
                T = SingleRotateWithLeft( T );
            else
                T = DoubleRotateWithLeft( T );
    }
    else if( X > T->Element )
    {
        T->Right = Insert( X, T->Right );
        if( Height( T->Right ) - Height( T->Left ) == 2 )
            if( X > T->Right->Element )
                T = SingleRotateWithRight( T );
            else
                T = DoubleRotateWithRight( T );
    }
    // Else X is in the tree already; do nothing

    T->Height = Max( Height(T->Left), Height(T->Right) ) + 1;
    return T;
}

// This function can be called only if K2 has a left child
// Perform a rotate between a note (K2) and its left child
// Update height, then return new root
static Position 
SingleRotateWithLeft( Position K2 )
{
    Position K1;

    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;

    K2->Height = Max( Height( K2->Left ), Height( K2->Right ) ) + 1;
    K1->Height = Max( Height( K1->Left ), Height( K2->Right ) ) + 1;

    return K1;  // New root
}

// This function can be called only if K3 has a left
// child and K3's left child has a right child
// Update heights, then return new root
static Position
DoubleRotateWithLeft( Position K3 )
{
    // Rotate between K1 and K2
    K3->Left = SingleRotateWithRight( K3->Left );

    // Rotate between K3 and K2
    return SingleRotateWithLeft( K3 );
}
