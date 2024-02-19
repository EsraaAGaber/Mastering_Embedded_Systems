#include<stdio.h>
#include<string.h>
void reverse(char s[],int n)
{
    char ans[100]="";
    int last = 0;
    for (int i = 0; i < n;i++)
    {
        if (s[i]==' ')
        {
            char t[100] = "";
            for (int j = last; j <= i;j++)
                t[strlen(t)] = s[j];
            strcat(t, ans);
            strcpy(ans, t);
            last = i + 1;
        }
    }
    strcpy(s, ans);
}
int main()
{
    char s[100];
    gets(s);
    s[strlen(s)] = ' ';
    reverse(s,strlen(s));
    printf("%s", s);
}
