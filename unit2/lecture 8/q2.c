#include<stdio.h>
int main()
{
    char alpa[26];
    char *p = alpa;
    for (int i = 0; i < 26;i++)
    {
        *p = ('a' + i);
        p++;
    }
    for (int i = 0; i < 26;i++)
    {
        printf("%c", alpa[i]);
    }
        return 0;
}
