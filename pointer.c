#include<stdio.h>

int main()
{
    int i =33;
    printf("%d\n",i);
    printf("%p\n",&i);
    int *j;
    *j=3;
    printf("%d\n",*j);
    return 0;
}
