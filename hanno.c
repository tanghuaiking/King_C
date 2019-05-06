#include<stdio.h>

//递归实现汉诺塔的移动
void mov(int n,char a,char b,char c)
{
    if (n==1)
    {
          printf ("%c->%c\n",a,c);
    }
    else
    { 
        mov(n-1,a,c,b);//第一次递归，表示把头上n-1块从a经c移动到b
        printf ("%c->%c\n",a,c);
        mov(n-1,b,a,c);//第二次递归，表示把剩下n-1块从b经a移动到c
     }
}

int main()
{
    int n;
    printf("请输入汉诺塔的圆饼数量\n");
    scanf("%d",&n);
    mov(n,'1','2','3');
    return 0;
}
