/*
    ex5.c
    Write C Program to check whether  character is an alphabet or not  
    Created on 12/12/2023
    Auther : Esraa abdelgaber

*/
#include<stdio.h>
int main()
{
    printf("Enter a character: ");
    char a;
    scanf("%c", &a);
    fflush(stdin);
    fflush(stdout);
    if ((a>='a'&&a<'z')||(a>='A'&&a<='Z'))
    printf ("%c is an alphabet",a);
    else printf ("%c is not an alphabet",a);
    return 0;
}
