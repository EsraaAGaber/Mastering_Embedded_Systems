/*
    ex7.c
    Write C Program to Find factorial of a number 
    Created on 24/2/2023
    Auther : Esraa abdelgaber

*/
#include<stdio.h>
int main()
{
    int n;
    long long  fac = 1;
    printf("Enter a integer: ");
    scanf("%d", &n);
    if (n<0)
    {
        printf ("Error!!! Factorial of negative number doesn't exist");
    }
    else {
    for (int i=1;i<=n;i++)
    fac*=i;
    printf ("Factorial = %d",fac);}
}
