#include<stdio.h>
#include<math.h>
double sqrtt(double  x)
{
    double st = 0, ed = x, ans = -1;
    while (ed-st>1e-6)
    {
        double mid = (st + ed)/2;
        if (abs(mid*mid-x)<1e-5)
        {
            ans = mid;
            break;
        }
        else if (mid*mid>x)
            ed =mid;
        else
            st = mid;
    }
    return ans;
}
int main()
{
    double  num;
    printf("Enter the number: ");
    scanf("%lf", &num);
    printf("the sqrt =%.3lf", sqrtt(num));
}
