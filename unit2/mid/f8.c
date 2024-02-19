#include<stdio.h>
void reverse(int x[],int n)
{
    for (int i = 0; i < n / 2;i++)
    {
        int t = x[i];
        x[i] = x[n - i - 1];
        x[n - i - 1] = t;
    }
}
int main()
{
    int num;
    printf("Enter the number of element : ");
    scanf("%d", &num);
    printf("Enter the elements : ");
    int x[100];
    for (int i = 0; i < num;i++)
        scanf("%d", &x[i]);
    reverse(x, num);
    for (int i = 0; i < num;i++)
        printf("%d ", x[i]);
}
