// A sulotion to the selection in c
//  sort the list( O(nlogn) )
//  pick the k-th element of the sorted list

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

int comp( const void *, const void * );

ElemType selectKth(ElemType *list, int n, int k)
{
    qsort(list, 10, sizeof(ElemType), comp);
    return list[k-1];
}

int comp(const void *x, const void *y)
{
    return ( *(int *)x - *(int *)y );
}

int main(void)
{
    ElemType list[] = {1, 2, 4, 5, 8, 3, 12, 34, 23, 45};
    printf("%d\n", selectKth(list, 10, 5) );

    return 0;
}
