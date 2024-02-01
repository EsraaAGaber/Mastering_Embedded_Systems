/*
    Auther : Esraa abdelgaber

*/
#include <stdio.h>
int main()
{
    float x[100] ,sum = 0;
    int n;
    printf("Enter the number of data : ");
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
    {
        printf("%d Enter Number : ",i+1);
        fflush(stdin);
        fflush(stdout);
        scanf("%f", &x[i]);
        sum += x[i];
    }
    printf("Average = %f", sum/n);
}
