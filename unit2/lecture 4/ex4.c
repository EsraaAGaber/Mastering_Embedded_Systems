/*
    Auther : Esraa abdelgaber

*/
#include <stdio.h>
int main()
{
    int x[100];
    int n;
    printf("Enter no of elements: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
    {
        scanf("%d", &x[i]); 
    }
    printf("Enter the element to be inserted : ");
    int num;
    scanf("%d", &num);
    int loc;
    printf("Enter the location : ");
    scanf("%d",&loc);
    for (int i = n; i >loc;i--)
    {
        x[i] = x[i-1];

    }
    x[loc - 1] = num;
    for (int i = 0; i <= n;i++)
        printf("%d ", x[i]);
}
