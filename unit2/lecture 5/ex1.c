/*
    Auther : Esraa abdelgaber

*/
#include <stdio.h>
#include <math.h>
void print_prim(int a,int b)
{
    for (int i = a; i <= b;i++)
    {
        char flag = 1;
        for (int j = 2; j <= sqrt(i);j++)
        {
            if(i%j==0)
            {
                flag = 0;
                break;
            }

        }
        if (flag)
            printf(" %d", i);
    }
}
void main()
{
    int a, b;
    printf("Enter two numbers(intervals): ");
    fflush(stdin);
    fflush(stdout);
    scanf("%d%d", &a, &b);
    printf("Prime numbers between %d and %d are:",a,b);
    print_prim(a, b);
}
