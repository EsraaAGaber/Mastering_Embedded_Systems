/*
    Auther : Esraa abdelgaber

*/
#include <stdio.h>
int main()
{
    char s[100];
    printf("Enter a string : ");
    fflush(stdin);
    fflush(stdout);
    gets(s);
    int a = 0,i=0;
    char c;
    printf("Enter a chatacter to find freq: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%c", &c);
    while (s[i]!='\0')
    {
        if (s[i]==c)
            a++;
        i++;
    }
    printf("freq of %c = %d",c, a);
}
