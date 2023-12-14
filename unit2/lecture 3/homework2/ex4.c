/*
    ex4.c
    Write C Program to check whether a number is positive or negative 
    Created on 12/12/2023
    Auther : Esraa abdelgaber

*/
#include<stdio.h>
int main()
{
    printf("Enter a number: ");
    float a;
    scanf("%f", &a);
    fflush(stdin);
    fflush(stdout);
    if (a>0)
    printf("%f is positive.",a);
    else if (a<0)
    printf("%f is negative.", a);
    else
    printf("You entered zero.");
    return 0;
}
