#include<stdio.h>
struct distance
{
    float inch, feet;
};
struct  distance sum(struct  distance a1,struct  distance a2)
{
    struct distance ans;
    ans.feet = a1.feet + a2.feet;
    ans.inch = a1.inch + a2.inch;
    ans.feet += (int)(ans.inch / 12);
    ans.inch -= ((int)(ans.inch / 12)) * 12;
    return ans;
};

int main()
{
    printf("Enter information for 1st distance:\n");
    struct distance a1,a2,dis;
    printf("Enter feet: ");
    scanf("%f",&a1.feet);
    printf("Enter inch: ");
    scanf("%f",&a1.inch);
    printf("Enter information for sec distance:\n");
    printf("Enter feet: ");
    scanf("%f",&a2.feet);
    printf("Entr inch: ");
    scanf("%f",&a2.inch);
    dis = sum(a1, a2);
    printf("Sum of distance =%f'-%f\"",dis.feet,dis.inch);
}
