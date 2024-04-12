#include<stdio.h>
int main()
{
    char str[30];
    char str_rev[30];
    char *p1 = str, *p2 = str_rev;
    int i = 0;
    printf("input a string :");
    scanf("%s", str);
    while (str[i]!='\0')    {
        p1++;
        i++;
    }
    while (i>=0)
    {p1--;
        *p2 = *p1;
        
        p2++;
        --i;
    }
    *p2 = '\0';
    printf("Reverse of the string is : %s\n\n\n",str_rev);
    return 0;
}
