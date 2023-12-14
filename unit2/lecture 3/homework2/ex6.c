/*
    ex6.c
    Write C Program to calculate sum of natural numbers 
    Created on 12/12/2023
    Auther : Esraa abdelgaber

*/
#include<stdio.h>
// int main()
// {
//     int n;
//     int sum = 0;
//     printf("Enter a integer: ");
//     scanf("%d", &n);
//     for (int i = 1; i <= n; i++)
//         sum += i;
//     printf("Sum = %d", sum);
// }
////or
int main()
{
    int n;
    int  sum = 0;
    printf("Enter a integer: ");
    scanf("%d", &n);
    sum = ((1 + n) * n )/ 2;
    printf("Sum = %d", sum);
}
