/*
    Auther : Esraa abdelgaber

*/
#include <stdio.h>
void print_rev(char s[],int sz)
{
    if (s[0]=='\0')
        return;
    print_rev(s + 1, sz);
    printf("%c", s[0]);
}
void main()
{
    char s[100];
    printf("Enter a sentence: ");
    fflush(stdin);
    fflush(stdout);
    gets(s);
    print_rev(s,100);
}
