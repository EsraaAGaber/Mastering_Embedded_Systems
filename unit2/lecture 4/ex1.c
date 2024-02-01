/*
    ex1.c
    Write C Program to find sum of two matrix of order 2*2
    Created on 2/2/2023
    Auther : Esraa abdelgaber

*/
#include <stdio.h>
int main()
{
    printf("Enter the element of 1st matrix\n");
    float x[2][2],y[2][2];
    for (int i = 0; i < 2;i++)
    {
        for (int j = 0; j < 2;j++)
       { 
        printf("Enter a%d%d : ",i+1,j+1);
        fflush(stdin);
        fflush(stdout);
        scanf("%f", &x[i][j]);
       }
    }
    printf("Enter the element of 2nd matrix\n");
    for (int i = 0; i < 2;i++)
    {
        for (int j = 0; j < 2;j++)
       { 
        printf("Enter b%d%d : ",i+1,j+1);
        fflush(stdin);
        fflush(stdout);
        scanf("%f", &y[i][j]);
       }
    }
        printf("Sum Of Matrix\n");
    for (int i = 0; i < 2;i++)
    {
        for (int j = 0; j < 2;j++)
       {

           printf("%f ", x[i][j] + y[i][j]);
       }
       printf("\n");
    }
    
}
