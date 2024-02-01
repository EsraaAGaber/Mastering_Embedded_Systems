/*
    Auther : Esraa abdelgaber

*/
#include <stdio.h>
#include<string.h>
int main()
{
    char s[100];
    printf("Enter a string : ");
    fflush(stdin);
    fflush(stdout);
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n / 2;i++)
    {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
    printf("Reverse string is : %s", s);
}
