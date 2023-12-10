/*
    ex4.c
    Write C Program to Multiply two Floating Point Numbers
    Created on 10/12/2023
    Auther : Esraa abdelgaber

*/
#include <stdio.h>
int main()
{
    float a, b;
    printf("Enter two numbers: ");
    scanf("%f%f", &a,&b);
    fflush(stdin);
    fflush(stdout);
    printf("Product: %f", a * b);
    return 0;
}
