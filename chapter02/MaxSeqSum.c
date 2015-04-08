
int MaxSubsequenceSum1( const int A[], int N )
{
    int ThisSum, MaxSum, i, j, k;

    MaxSum = 0;
    for( i = 0; i < N; i++)
        for( j = i; j < N; j++)
        {
            ThisSum = 0;
            for( k = i; k <=j; k++)
                ThisSum += A[k];

            if( ThisSum > MaxSum )
                MaxSum = ThisSum;
        }
    return MaxSum;
}

// O(N^2)
int MaxSubsequenceSum2( const int A[], int N )
{
    int ThisSum, MaxSum, i, j;

    MaxSum = 0;
    for( i = 0; i < N; i++ )
    {
        ThisSum = 0;
        for( j = i; j < N; j ++ )
        {
            ThisSum += A[j];

            if( ThisSum > MaxSum )
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}

// 分治策略 O(NlogN)
static MaxSubSum( const int A[], int Left, int Right )
{
    int MaxLeftSum, MaxRightSum;
    int MaxLeftBorderSum, MaxRightBorderSum;
    int LeftBorderSum, LeftBorderSum;
    int Center, i;

    // Base Case
    if( Left == Right )
        if( A[Left] > 0 )
            return A[Left];
        else
            return 0;

    // Mpving Progress
    Center = ( Left + Right ) / 2;
    MaxLeftSum = MaxSubSum( A, Left, Center );
    MaxRightSum = MaxSubSum( A, Center + 1, Right );

    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;
    for( i = Center; i >= Left; i-- )
    {
        LeftBorderSum += A[i];
        if( LeftBorderSum > MaxLeftBorderSum )
            MaxLeftBorderSum = LeftBorderSum;
    }

    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for( i = Center + 1; i <= Right; i++ )
    {
        RightBorderSum += A[i];
        if( RightBorderSum > MaxRightBorderSum )
            MaxRightBorderSum = RightBorderSum;
    }

    return Max3( MaxLeftSum, MaxRightSum,
            MaxLeftBorderSum + MaxRightBorderSum );
}

// O(N)
int MaxSubSum4( const int A[], int N )
{
    int ThisSum, MaxSum, j;

    ThisSum = MaxSum = 0;
    for( j = 0; j < N; j++ )
    {
        ThisSum += A[j];

        if( ThisSum > MaxSum )
            MaxSum = ThisSum;
        else if( ThisSum < 0 )
            ThisSum = 0;
    }
    return MaxSum;
}
