#include <stdio.h>
int main()
{
    int m=29;
    printf("Address of m : %x\nvalue of m : %d\n\n", &m, m);
    int *ab = &m;
    printf("now ab is assigned with address of m\n");
    printf("Address of pointer ab : %x\ncontent of pointer ab : %d\n\n", ab, *ab);
    printf("The value of m is assigned to 34 now.");
    m = 34;
    printf("Address of pointer ab : %x\ncontent of pointer ab : %d\n\n", ab, *ab);
    *ab = 7;
    printf("The pointer variable ab is assigned with 7.");
    printf("Address of m : %x\nvalue of m : %d\n\n", &m, m);

    return 0;
}
