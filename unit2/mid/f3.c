#include<stdio.h>
void print(int a,int b)
{
    for (int i = a; i <= b; i++)
    {
        short ok = 1;
        for (int j = 2; j * j <= i;j++)
        {
            if (i%j==0){
                ok = 0;
                break;
            }
        }
        if (ok)
            printf("%d ", i);
    }
}
int main()
{
    int l,r;
    printf("Enter two numbers number: ");
    scanf("%d%d", &l,&r);
    print(l, r);
}
