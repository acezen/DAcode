#ifndef _Adjust_linkedlist_h
#define _Adjust_linkedlist_h

typedef int ElementType;

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode adjustList;
typedef PtrToNode Position;

adjustList CreateList( adjustList L );
int IsEmpty( adjustList L );
int IsLast( Position P, adjustList L );
void Find( ElementType X, adjustList L );
void Delete( ElementType X, adjustList L );
Position FindPrevious( ElementType X, adjustList L );
void Insert( ElementType X, adjustList L );
void DeleteList( adjustList L );
Position Header( adjustList L );
Position First( adjustList L );
Position Advance( Position P );
ElementType Retrieve( Position P );
void PrintList( const adjustList L );

struct Node
{
    ElementType Element;
    PtrToNode   Next;
};

#endif
