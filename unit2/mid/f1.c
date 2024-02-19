#include<stdio.h>
int sum(int x)
{
    int ans = 0;
    while (x!=0)
    {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("the sum =%d", sum(num));
}
