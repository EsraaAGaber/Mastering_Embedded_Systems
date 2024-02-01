/*
    Auther : Esraa abdelgaber

*/
#include <stdio.h>
int main()
{
    int x[100][100],y[100][100];
    int n,m;
    printf("Enter rows and column of matrix:  ");
    scanf("%d%d", &n,&m);
    printf("Enter elements of matrix:  ");
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {   printf("Enter element a%d%d : ",i+1,j+1);
            fflush(stdin);
            fflush(stdout);
            scanf("%d", &x[i][j]);y[j][i] = x[i][j];
        }
    }
    printf("Entered Matrix:\n");
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        { 
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
    printf("transpose of  Matrix:\n");
    for (int j = 0; j < m;j++)
    {
        for (int i = 0; i < n;i++)
        { 
            printf("%d ", y[j][i]);
        }
        printf("\n");
    }
}
