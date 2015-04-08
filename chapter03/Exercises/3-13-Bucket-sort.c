#include <stdio.h>
#include <stdlib.h>
#include "../list.h"
#include "../fatal.h"

// 定义桶
struct BucketRecord
{
    int Capacity;
    PtrToNode *Array;
};

typedef struct BucketRecord *Bucket;    // 定义Bucket为指向BucketArray的指针

// 三个取位函数
int gewei( ElementType X )
{
    return X % 10;
}

int shiwei( ElementType X )
{
    return (X / 10) % 10;
}

int baiwei( ElementType X )
{
    return (X / 100) % 10;
}

// Ratio sort implementation
void BucketSort( int len, ElementType records[] )
{
    Bucket B;
    int i, j, k, count;     // count为排序躺数,i, j, k为循环控制变量

    // Bucket初始化
    B = malloc( sizeof( struct BucketRecord ) );
    if( B == NULL )
        FatalError( "Out of space!!!" );
    B->Capacity = 10;
    B->Array = malloc( sizeof( PtrToNode ) * 10 );
    if( B->Array == NULL )
        FatalError( "Out of space!!!" );
    for( i = 0; i < 10; i++ )
        B->Array[i] = MakeEmpty( NULL );    // 数组里每个List元素初始化
   
    // 排序主体, 最低位优先(LSD),共3趟
    for( count = 0; count < 3; count++ )
    {
        for( i = 0; i < len; i++ )  // 分配, 将records中各元素分配到桶中
        {
            int record = records[i];
            switch( count )
            {
                case 0:
                    InsertLast( record, B->Array[ gewei(record) ] );
                    break;
                case 1:
                    InsertLast( record, B->Array[ shiwei(record) ] );
                    break;
                case 2:
                    InsertLast( record, B->Array[ baiwei(record) ] );
                    break;
                default:
                    break;
            }
        }

        j = 0;
        while( j < len )            // 收集, 从各个桶中回收元素到records中
        {
            for( k = 0; k < 10; k++ )
            {
                Position P;

                P = First( B->Array[k] );
                while( P != NULL )
                {
                    records[j] = P->Element;
                    P = Advance( P );
                    j++;
                }
                B->Array[k] = MakeEmpty( B->Array[k] );     // 收集完后将该桶置空，方便下次使用
            } // for
        } // while
    } // for
}

/* 
int main( void )
{
    int len = 16;
    int i;
    int students[] = { 12, 243, 23, 45, 89, 675, 453, 102, 197, 389, 1, 0, 78, 8, 567, 456 };

    BucketSort( len, students );
    
    // print
    for( i = 0; i < len; i++ )
    {
        printf("%d ", students[i] );
    }
    printf( "\n" );

    return 0;
} 
*/
