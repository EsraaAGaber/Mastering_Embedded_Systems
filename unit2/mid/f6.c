#include<stdio.h>
#include<string.h>
int fun(int arr[],int n)
{
    int frq[100]={0};
    int ans = 0;
    for (int i = 0; i < n;i++)
    {
        if (frq[arr[i]]==1)
            ans -= arr[i];
        frq[arr[i]]++;
        if (frq[arr[i]]==1)
        ans += arr[i];
    }
    return ans;
}
int main()
{
    int n;
    printf("enter the size of the array : ");
    scanf("%d", &n);
    int x[100];
    printf("enter the elements :\n");
    for (int i = 0; i < n;i++)
    {
        scanf("%d", &x[i]);
    }
    printf("the unique number is %d", fun(x, n));
}
