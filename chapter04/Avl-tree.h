#ifndef _Avl_h
#define _Avl_h

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty( AvlTree T );
Position Find( ElementType X, AvlTree T );
Position FindMin( ElementType X, AvlTree T );
Position FindMax( AvlTree T );
AvlTree Insert( ElementType X, AvlTree T );
AvlTree Delete( ElementType X, AvlTree T );
ElementType Retrieve( Position P );

struct AvlNode
{
    ElementType Element;
    AvlTree     Left;
    AvlTree     Right;
    int         Height;
};

#endif
