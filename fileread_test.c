#include <stdlib.h>
#include<stdio.h>
#include<math.h>     
#include <string.h>

int  c1_B,c2_L,c3_FLUE;
int main(void) 
{
    FILE *fp1;
    char buf[1024];                                
    if( (fp1=fopen("test.txt","r"))==NULL )
    {
        printf("打开输入文件失败，可能文件还没有创建!\n");
        exit(0);
    }
    int nn=0;
    while(!feof(fp1))
    {
        fscanf(fp1,"(%d,%d) %d",&c1_B,&c2_L,&c3_FLUE);
        printf("%d,%d,%d\n",c1_B,c2_L,c3_FLUE); 
        if(feof(fp1)) break;
        memset(buf, 0, 1024); 
        fgets(buf,1024,fp1);
    }
    fclose(fp1);
    return 0;
}

