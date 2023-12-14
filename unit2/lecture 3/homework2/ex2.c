/*
    ex2.c
    Write C Program check vowel or consonant
    Created on 12/12/2023
    Auther : Esraa Abdelgaber

*/
#include<stdio.h>
int main()
{
    printf("Enter an alphabet :");
    char a;
    scanf("%c", &a);
 
    if (a=='i'||a=='a'||a=='e'||a=='y'||a=='u'||a=='o'||(a=='I'||a=='A'||a=='E'||a=='Y'||a=='U'||a=='O'))
        printf("%c is a vowel.",a );
    else
        printf("%c is a consonant ", a);
    return 0;
}
