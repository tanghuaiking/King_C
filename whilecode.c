#include<stdio.h>

int main(void)
{
    unsigned long sum =0ul;
    unsigned int i=1;
    unsigned int count =0;
    printf("\nthe number of integer you want to sum:");
    scanf("%u",&count);
    while(i<=count)
        sum +=i++;	 
    printf("Total of the list %u numbers is %lu\n",count,sum);
    return 0;
}
