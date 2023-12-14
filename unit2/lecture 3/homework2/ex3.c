/*
    ex3.c
    Write C Program get the max of three numbers 

    Created on 12/12/2023
    Auther : Esraa Abdelgaber

*/
#include<stdio.h>
int main()
{
    float  a, b, c;
    printf("Enter three numbers ");
    fflush(stdin);
    fflush(stdout);
    scanf("%f%f%f", &a,&b,&c);
    fflush(stdin);
    fflush(stdout);
    if (a>=b&&a>=c)
        printf("Lasrgest numbr = %f", a);
    else if (b>=a&&b>=c)
        printf("Lasrgest numbr = %f", b);
    else         
        printf("Lasrgest numbr = %f", c);
    return 0;
}
