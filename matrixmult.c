#include<stdio.h>

int p,q,k;
int fun(float A[][2],float B[][1])
{
    float C[2][1]={0};
    for (p=0;p<2;++p)
    {
        for(q=0;q<1;++q)
        {
            for(k=0;k<2;++k)
                C[p][q] +=A[p][k]*B[k][q];
        }
    }

    for(p=0;p<2;p++)
    {
        for (q=0;q<1;q++)
        {
            printf("%f",C[p][q]);
            printf("\n");
        }
    }
    return 0;
}

int main()
{
    float A[2][2]={1,1,2,1},B[2][1]={2,1};
    printf ("矩阵A与B的乘积为：\n");
    fun(A,B);
    return 0;
}
