#ifndef _Circular_list_h

typedef int ElementType;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

List MakeEmpty( List L );
int IsEmpty( List L );
int IsHeader( List L );
int IsLast( Position P, List L );
void RemoveAndPrint( Position P, List L );
void InsertLast( ElementType X, List L );
Position FindPrevious( Position P, List L );
void DeleteList( List L );
Position Advance( Position P );
Position Header( List L );
Position First( List L );

#endif  // _Circular_list_h

