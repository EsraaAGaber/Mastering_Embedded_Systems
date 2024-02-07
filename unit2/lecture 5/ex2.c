/*
    Auther : Esraa abdelgaber

*/
#include <stdio.h>
#include <math.h>
int  fac(int a)
{
    if (a==1)
        return 1;
    return a * fac(a - 1);
}
void main()
{
    int a;
    printf("Enter an positive interger: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%d", &a);
    printf("Factorial of %d = ",fac(a));
}
