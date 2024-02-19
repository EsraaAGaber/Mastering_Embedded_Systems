#include<stdio.h>
int count(int x)
{
    int ans = 0;
    while (x)
    {
        x &= (x - 1);
        ans++;
    }
    return ans;
}
int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("the number of ones = %d", count(num));
}
