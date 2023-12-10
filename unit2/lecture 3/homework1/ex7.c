/*
    ex7.c
    Write Source Code to Swap Two Numbers without temp variable.
    Created on 10/12/2023
    Auther : Esraa abdelgaber

*/
//if a,b wew float

#include <stdio.h>
int main()
{
    float  a, b;
    printf("Enter value of a: ");
    scanf("%f", &a);
    fflush(stdin);
    fflush(stdout);
    printf("Enter value of b: ");
    scanf("%f", &b);
    fflush(stdin);
    fflush(stdout);
    a+=b;
    b =a-b;
    a =a-b;
    printf ("After swapping, value of a = %f\nAfter swapping, value of b = %f",a,b);
    return 0;
}



// if a,b intger

// #include <stdio.h>
// int main()
// {
//     int   a, b;
//     printf("Enter value of a: ");
//     scanf("%d", &a);
//     fflush(stdin);
//     fflush(stdout);
//     printf("Enter value of b: ");
//     scanf("%d", &b);
//     fflush(stdin);
//     fflush(stdout);
//     a^=b;
//     b ^= a;
//     a^=b;
//     printf ("After swapping, value of a = %d\nAfter swapping, value of b = %d",a,b);
//     return 0;
// }
