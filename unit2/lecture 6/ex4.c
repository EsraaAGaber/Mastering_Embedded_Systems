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
    struct student st1[10];
    for (int i = 0; i < 10;i++)
       { printf("for roll number %d \n",i+1);
           st1[i].roll = i + 1;
           printf("Enter name: " );

           scanf("%s", st1[i].name);

           printf("Enter marks: ");
           scanf("%f", &st1[i].marks);
        }
    printf("Displaying information of students:\n");
    for (int i = 0; i < 10;i++)
       {
           printf("information for roll number %d \n", i + 1);
           printf("name: %s\nMarks: %f\n", st1[i].name, st1[i].marks);
        }
}
