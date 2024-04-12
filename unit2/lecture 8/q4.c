#include<stdio.h>
int main()
{
    int arr[15];
    int n;
    int *p = arr;
    printf("Input the number of elements to store in the array (max 15)");
    scanf("%d", &n);
    printf("Input %d number of elements in the array :\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("element-%d:", i + 1);
        scanf("%d", p);
        p++;
    }
    int arr_rev[15];
    int *p_re = arr_rev;
    
    for (int i = n - 1; i >= 0;i--)
    {p--;
        *p_re = *p;
        
        p_re++;
    }
    for (int i = 0; i < n; i++)
    {
        printf("element-%d : %d\n", i + 1,arr_rev[i]);
        
    }


        return 0;
}
