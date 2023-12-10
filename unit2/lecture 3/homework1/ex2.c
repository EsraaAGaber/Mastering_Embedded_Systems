/*
    ex2.c
    Write C Program to Print a Integer Entered by a User
    Created on 10/12/2023
    Auther : Esraa abdelgaber

*/
#include <stdio.h>
int main()
{
    int x;
    printf("Enter a integer: ");
    scanf("%d", &x);
    fflush(stdin);
    fflush(stdout);
    printf("You entered: %d\r\n",x);
    return 0;
}
