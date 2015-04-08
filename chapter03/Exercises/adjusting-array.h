#ifndef _Adjusting_array_h
#define _Adjusting_array_h

typedef int ElementType;
struct arrayRecord;
typedef struct arrayRecord *adjustList;

adjustList CreatList( int MaxElements );
void MakeEmpty( adjustList L );
int IsEmpty( adjustList L );
int IsFull( adjustList L );
void Insert( ElementType X, adjustList L );
void Delete( ElementType X, adjustList L );
void Find( ElementType X, adjustList L );
void PrintList( adjustList L );

#define MinListSize (5)
struct arrayRecord
{
    int length;             // 当前长度
    int Capacity;           
    ElementType *Array;
};

#endif
