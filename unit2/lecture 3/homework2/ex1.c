/*
    ex1.c
    Write C Program check if a number is even or odd
    Created on 12/12/2023
    Auther : Esraa Abdelgaber

*/
#include<stdio.h>
int main()
{
    printf("Enter an interger you want to check : ");
    int a=5;
    scanf("%d", &a);
    if ((a&1)==0)
        printf("%d is even", a);
    else
        printf("%d is odd", a);
    return 0;
}
