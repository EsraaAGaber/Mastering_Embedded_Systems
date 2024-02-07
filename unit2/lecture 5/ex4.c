/*
    Auther : Esraa abdelgaber

*/
#include <stdio.h>
int power(int n,int cnt)
{
    if (cnt==1)
        return n;
    return n * power(n, cnt - 1);
}
void main()
{
    int b, p;
    printf("Enter base number: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%d", &b);
    printf("Enter power number(positive interger): ");
    fflush(stdin);
    fflush(stdout);
    scanf("%d", &p);
    printf("%d^%d = %d",b,p,power(b, p));
}
