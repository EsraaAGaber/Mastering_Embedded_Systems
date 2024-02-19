#include<stdio.h>
int reverse(int x)
{
    int ans = 0;
    while (x!=0)
    {
        ans *= 10;
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
    printf("the reverse = %d", reverse(num));
}
// assume zero in first positions will be ignore if else we can use strings 
