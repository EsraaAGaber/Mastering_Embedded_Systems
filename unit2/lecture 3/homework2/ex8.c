/*
    ex8.c
    Write C Program to make simple calculator to add ,subtract ,multiply or divide using switch cace 
    Created on 12/12/2023
    Auther : Esraa abdelgaber

*/
#include<stdio.h>
int main()
{
    char c;
    float a,b;
    printf ("Enter operator either + or - or * or divide : ");
    scanf("%c",&c);
    fflush(stdin);
    fflush(stdout);
    printf("Enter two operands: ");
    scanf("%f%f", &a, &b);
    switch (c)
    {
    case '+':
        printf("%f %c %f = %f", a, c, b, a + b);
        break;
    case '-':
        printf("%f %c %f = %f", a, c, b, a - b);
        break;
    case '*':
        printf("%f %c %f = %f", a, c, b, a * b);
        break;
    case '/':
        printf("%f %c %f = %f", a,c ,b , a / b);
        break;
    default:
        printf("invalid input ");
        break;
    }
}
