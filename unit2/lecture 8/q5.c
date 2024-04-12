// pointer to array of pointers --->to a struct;
#include<stdio.h>
struct emplyee
{
    char Name[10];
    int id;
};

int main()
{
    struct emplyee arr[5];
    for (int i = 0; i < 2;i++)
    {
        printf("enter the name and id of emplyee number  %d\n", i + 1);
        scanf("%s", arr[i].Name);
        scanf("%d",&arr[i].id) ;
    }
    struct emplyee *p1[] = {&arr[0], &arr[1]};
    struct emplyee *(*arr_p)[2] = &p1;
    for (int i = 0; i < 2;i++)
    {
        printf("Exmployee Name : %s\nEmployee ID : %d\n\n", (*(*arr_p+i))->Name,(*(*arr_p+i))->id);
    }

        return 0;
}
