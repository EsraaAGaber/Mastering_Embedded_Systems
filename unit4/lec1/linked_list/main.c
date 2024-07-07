
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdint.h"
#define Eprint(...)          \
    {                        \
        fflush(stdin);       \
        fflush(stdout);      \
        printf(__VA_ARGS__); \
        fflush(stdin);       \
        fflush(stdout);      \
    }
struct data
{
    int id;
    char name[40];
    float hight;
};
struct node
{
    struct node *next;
    struct data student;
};

struct node *header_node = NULL;
void add_student()
{
    char input[40];
    float f;
    int x;
    struct node *newstudent = (struct node *)malloc(sizeof(struct node));
    struct node *student = header_node;

    Eprint("\nEnter student ID :");
    scanf("%d", &x);
    newstudent->student.id = x;
    Eprint("\nEnter student name :");
    scanf("%s", (newstudent->student.name));
    Eprint("\nEnter student height :");
    scanf("%f", &f);
    newstudent->student.hight = f;

    if (header_node == NULL)
    {
        header_node = newstudent;
    }
    else
    {
        while (student->next)
        {
            student = student->next;
        }
        student->next = newstudent;
    }
    newstudent->next = NULL;
    Eprint("\n add done \t");
}
void delete_student()
{
    unsigned int ID;
    Eprint("\n enter the student Id to be deleted :");
    scanf("%d", &ID);
    if (header_node == NULL)
    {
        Eprint("\n list is empty\t");
    }
    else
    {
        struct node *student = header_node;
        struct node *Prv_student = NULL;

        while (student)
        {
            if (student->student.id == ID)
            {
                if (Prv_student)
                {
                    Prv_student->next = student->next;
                }
                else
                    header_node = student->next;
                free(student);
                Eprint("\nprocess done \n");
                return;
            }
            Prv_student = student;
            student = student->next;
        }
        Eprint("\n not found\n");
    }
}
void veiw_all()
{
    if (header_node == NULL)
    {
        Eprint("\n empty list\t");
    }
    else
    {
        int i = 1;
        struct node *student = header_node;
        while (student != NULL)
        {
            Eprint("\nno %d", i++);
            Eprint("\nID :%d", student->student.id);
            Eprint("\nname :%s", student->student.name);
            Eprint("\nhight :%f", student->student.hight);

            student = student->next;
        }
    }
}
void delete_all()
{
    if (header_node != NULL)
    {

        int i = 1;
        struct node *student = header_node;
        while (student)
        {
            struct node *temp;
            temp = student;
            student = student->next;
            free(temp);
        }
    }
    header_node = NULL;
}

struct node *get_nth(struct node *student, int cnt)
{
    if (cnt == 1)
        return student;
    if (student->next)
        return get_nth(student->next, cnt - 1);
    return NULL;
}
unsigned int get_lenght(struct node *student)
{

    if (student->next)
        return get_lenght(student->next) + 1;
    return 1;
}
struct node *get_from_end(int indx)
{
    if (header_node)
    {
        int i = 0;
        struct node *student = header_node;
        struct node *student_req = header_node;

        while (student)
        {

            student = student->next;
             if (i >= indx)
                student_req = student_req->next;
            i++;
        }
        return student_req;
    }
    return NULL;
}
struct node *get_mid()
{
    if (header_node != NULL)
    {
        int i = 0;
        struct node *student = header_node;
        struct node *student_req = header_node;

        while (student)
        {

                student = student->next;
            if (student)
               { student->next;

            student_req = student_req->next;}
        }
        return student_req;
    }
    return NULL;
}
void reverse()
{
    if (header_node != NULL)
    {

        struct node *student = header_node;
        struct node *Prv_student = NULL;
        struct node *PP = NULL;

        while (student)
        {
            PP = student->next;
            student->next=Prv_student;
            Prv_student = student;
            student = PP;


        }
        header_node = Prv_student;
veiw_all();
        Eprint("\nDonereverse \n");
    }
    else
    {
        Eprint("\nempty list");
    }
}

void main()
{
    char _text[10];

    while (1)
    {

        Eprint("\n---------------------------\n");
        Eprint(" Choose on of the following Options \n ");
        Eprint(" 1: Add_Student \n");
        Eprint(" 2: Delete_Student \n");
        Eprint(" 3: Display_all_students \n");
        Eprint(" 4: Delete_all_students: \n");
        Eprint(" 5: get_nth student \n");
        Eprint(" 6: Display_the_length \n");
        Eprint(" 7: Display_By_Index_from_end \n");
        Eprint(" 8: Middle_node \n");
        Eprint(" 9: Reverse_list \n");
        int indx;
        struct node *x;
        gets(_text);
        Eprint("\n---------------------------\n");
        switch (atoi(_text))
        {
        case 1:
            add_student();
            break;
        case 2:
            delete_student();
            break;
        case 3:
            veiw_all();
            break;
        case 4:
            delete_all();
            break;
        case 5:
            Eprint("\nenter the nth to be search : ");
            scanf("%d", &indx);
            struct node *x = get_nth(header_node, indx);
            if (x == NULL)
            {
                Eprint("\nNOTalid");
            }
            else
            {
                Eprint("\nid :%d\nname :%s\nhigth :%f", x->student.id, x->student.name, x->student.hight);
            }
            break;
        case 6:
            Eprint("the length =%d", get_lenght(header_node));
            break;
        case 7:
            Eprint("\nenter the index from end to be search : ");
            scanf("%d", &indx);
            x = get_from_end(indx);
            if (x == NULL)
            {
                Eprint("\nNOTalid");
            }
            else
                Eprint("\nid :%d\nname :%s\nhigth :%f", x->student.id, x->student.name, x->student.hight);
            break;
        case 8:
            x = get_mid();
            if (x == NULL)
            {
                Eprint("\nNOTalid");
            }
            else
                Eprint("\nid :%d\nname :%s\nhigth :%f", x->student.id, x->student.name, x->student.hight);
            break;
        case 9:
            reverse();
            break;
        default:
            Eprint("\n Wrong Option \n Please Try again\n");
            break;
        }
    }
}
