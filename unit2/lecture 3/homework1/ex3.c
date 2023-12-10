/*
    ex3.c
    Write C Program to Add Two Integers
    Created on 10/12/2023
    Auther : Esraa abdelgaber

*/
#include <stdio.h>
int main()
{
    int a, b;
    printf("Enter two integers: ");
    scanf("%d%d", &a, &b);
    fflush(stdin);
    fflush(stdout);
    printf("Sum: %d", a + b);
    return 0;
}
