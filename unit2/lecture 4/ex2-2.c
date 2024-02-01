/*
    Auther : Esraa abdelgaber

*/
#include <stdio.h>
int main()
{
    char s[100];
    printf("Enter a string : ");
    scanf("%s", s);
    int a = 0;
    while (s[a]!='\0')
    {
        a++;
    }
    printf("Length of string : %d", a);
}
