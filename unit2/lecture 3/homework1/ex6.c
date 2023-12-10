/*
    ex6.c
    Write Source Code to Swap Two Numbers
    Created on 10/12/2023
    Auther : Esraa abdelgaber

*/
 #include <stdio.h>
int main()
{
    float  a, b;
    printf("Enter value of a: ");
    scanf("%f", &a);
    fflush(stdin);
    fflush(stdout);
    printf("Enter value of b: ");
    scanf("%f", &b);
    fflush(stdin);
    fflush(stdout);
    float t = a;
    a = b;
    b = t;
    printf ("After swapping, value of a = %f\nAfter swapping, value of b = %f",a,b);
    return 0;
}


