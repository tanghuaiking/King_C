#include<stdio.h>
#include <string.h>
#include<stdlib.h>

int main(void)
{
 int x=6;
 FILE *fp=fopen("text.txt","w");
 fprintf(fp,"yes you are right ！\ny=4+%d\n",x);
 fclose(fp);  


//rename
if(rename("text.txt","yes.txt"))
	printf("Failed.\n");
else
	printf("Good.\n");

//remove("yes.txt");
} 
