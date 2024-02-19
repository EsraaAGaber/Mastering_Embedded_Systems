#include<stdio.h>
#include<string.h>
int count (char arr[],int n)
{
    int mx = 0;
    int last = -1;
    for (int i = 0; i < n;i++)
    {
        if (arr[i]=='0')
        {
            last = i;
            break;
        }
    }
    int c = 0;
    for (int i = last; i < n;i++)
    {
        if (arr[i]=='0')
        {
            if (mx<c)
                mx = c;
            last = i;
        }
        else if (arr[i]=='1')
            c++;
    }
    return mx;
}
int main(){
    char x[100];
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n;i++)
    {
        scanf("%c", &x[i]);
    }
    printf("max number of ones = %d", count(x, n));
}
