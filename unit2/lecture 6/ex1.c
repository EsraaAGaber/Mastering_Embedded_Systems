#include<stdio.h>
struct student
{
    char name[50];
    int roll;
   float marks;
};

int main()
{
    printf("Enter information of students:\n");
    struct student st1;
    printf("Enter name: ");
    scanf("%s",st1.name);
     printf("Enter roll number: ");
    scanf("%d",&st1.roll);
     printf("Enter marks: ");
    scanf("%f",&st1.marks);
    printf("Displaying information\n");
    printf("name: %s\nRoll: %d\nMarks: %f", st1.name, st1.roll, st1.marks);
}
