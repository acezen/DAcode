/* 此算法将表中相同的元素删除，空间复杂度为O(NlogN)
 * 思想：
 *  现将数组排序，再进行删除操作
 *
 */

#include <stdio.h>
#include <stdlib.h>

int comp( const void *x, const void *y )
{
    return ( *(int *)x - *(int *)y );
}

void Delete_dulplicas( int A[], int N)
{
    // 将数组排序
    qsort( A, N, sizeof(int), comp );

    int i, j;       // i 保存第一个不相同的元素，j工作索引
    for( i = 0, j = 1; j < N; j++ )
    {
        if( A[i] < A[j] )       // 查找下一个于元素不同的元素，找到则前移
            A[ ++i ] = A[ j ];
    }
    
    N = i + 1;
    for( i = 0; i < N; i++ )
        printf("%d ", A[i] );
    printf( "\n" );
}

int main( void )
{
    int A[] = { 12, 3, 5, 2, 56, 34, 14, 5, 8, 34, 2, 12, 2, 7, 10 };

    Delete_dulplicas( A, 15 );
    return 0;
}



