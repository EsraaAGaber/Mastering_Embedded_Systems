/*
    ex5.c
    Write C Program to Find ASCII Value of a Character
    Created on 10/12/2023
    Auther : Esraa abdelgaber

*/
#include<stdio.h>
int main()
{
    char a;
    printf("Enter a character: ");
    scanf("%c", &a);
    fflush(stdin);
    fflush(stdout);
    printf("ASCII value of %c = %d", a, a);
    return 0;
}
