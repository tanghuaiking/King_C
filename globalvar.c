#include<stdio.h>

int count =0;

void test1(void);
void test2(void);
void test3(void);

int main(void)
{
    for(int i=0;i<5;++i)
    {
        test1();
        test2();
        test3();
    }
    return 0;
}

//global
void test1(void)
{
    printf("test1 count=%d\n",++count);
}

//static
void test2(void)
{
    static int count =0;
    printf("test2 count = %d\n",++count);
}

void test3(void)
{
    int count2 =0;
    printf("test3 count = %d\n",++count2);
}
