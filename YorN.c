//are you sure
#include <stdio.h>

int main(void)
{
    char answer = 0;  //stores an input character 
    printf("Do you really like ziwei.\nEnter Y or N:");
    scanf(" %c",&answer);
	
    switch(answer)
    {
        case 'y':case'Y':
            printf("Good Boy.\n");
            break;			 
        case 'n':case 'N':
            printf("really?????\n");
            break;
        default:
        printf("Are you sure ...\n");
        break;
    }
    return 0;
}	
