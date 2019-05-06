#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char letter = 0;
    printf("Enter an  uppercase letter:");
    scanf("%c", &letter);
    if(isalpha(letter) && isupper(letter))
        printf("you enter an uppercase %c.\n",letter);
    else
        printf("SB .\n");
	//return 0;
    letter +='a'-'A';
    if(isalpha(letter) && islower(letter))
        printf("now,you enter an lowercase %c.\n",letter);  //tolower()
    else
        printf("SB +1.\n");
    return 0;	
}
