#include<stdio.h>
struct number
{
    float r, i;
};
struct number sum(struct number num1,struct number num2)
{
    struct number ans={num1.r+num2.r,num1.i+num2.i};
    return ans;
}

int main()
{
    struct number num1,num2;
    printf("Enter real and imaginary respectively: ");
    scanf("%f%f",&num1.r,&num1.i);
    printf("Enter real and imaginary respectively: ");
    scanf("%f%f",&num2.r,&num2.i);
    struct number ans = sum(num1, num2);
    printf("Sum=%f+%fi", ans.r, ans.i);
}
