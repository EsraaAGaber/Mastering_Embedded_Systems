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
    printf("Enter the element to be searched : ");
    int num;
    scanf("%d", &num);
    for (int i = 0; i < n;i++)
    {
        if (x[i]==num)
        {
            printf("Number found at location %d", i + 1);
            return 0;
        }

    }
    printf("Number not found");
    return 0;
}
