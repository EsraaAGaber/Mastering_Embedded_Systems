
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef struct {
    char fname[20];
    char lname[20];
    int roll;
    float GPA;
    int SUBJECTS[4];
} Data;

#define element_type Data
#define width 50
element_type students_buffer[width];

typedef struct {
    unsigned int length;
    unsigned int count;
    element_type *base;
    element_type *head;
    element_type *tail;
} FIFO_buf_t;

typedef enum {
    FIFO_no_error,
    FIFO_full,
    FIFO_empty,
    FIFO_null
} FIFO_buf_status;




FIFO_buf_status FIFO_init(FIFO_buf_t* FIFO_buf, element_type* buf, unsigned int length) {
    if (buf == NULL)
        return FIFO_null;
    FIFO_buf->base = buf;
    FIFO_buf->head = buf;
    FIFO_buf->tail = buf;
    FIFO_buf->count = 0;
    FIFO_buf->length = length;
    return FIFO_no_error;
}

FIFO_buf_status FIFO_enqueue(FIFO_buf_t* FIFO_buf, element_type item) {
    if (!FIFO_buf->base || !FIFO_buf->head || !FIFO_buf->tail)
        return FIFO_null;
    if (FIFO_buf->count == FIFO_buf->length) return FIFO_full;
    *(FIFO_buf->head) = item;
    FIFO_buf->count++;
    if ((FIFO_buf->head) - (FIFO_buf->base) == ((FIFO_buf->length) * sizeof(element_type)))
        FIFO_buf->head = FIFO_buf->base;
    else
        FIFO_buf->head++;
    return FIFO_no_error;
}

// Uncomment and fix the dequeue function if needed
// FIFO_buf_status FIFO_dequeue(FIFO_buf_t* FIFO_buf, unsigned int* item) {
//     if (!FIFO_buf->base || !FIFO_buf->head || !FIFO_buf->tail)
//         return FIFO_null;
//     if (FIFO_buf->count == 0) return FIFO_empty;
//     FIFO_buf->count--;
//     *item = *((FIFO_buf->tail)->roll);
//     if ((FIFO_buf->tail) - (FIFO_buf->base) == ((FIFO_buf->length) * sizeof(element_type)))
//         FIFO_buf->tail = FIFO_buf->base;
//     else
//         FIFO_buf->tail++;
//     return FIFO_no_error;
// }
FIFO_buf_status find(FIFO_buf_t* students_data,int id){
	
	element_type* temp;
		int i;
	
	 temp=students_data->tail;
		for (i=0;i<students_data->count;i++)
		{
			if ((temp)->roll==id)
			{
				return FIFO_no_error;
			}
			if (temp==students_data->base+ ((students_data->length) * sizeof(element_type) ))
				temp=students_data->base;
			else temp++;
		}
        return FIFO_null;
}
void FIFO_print(FIFO_buf_t* FIFO_buf) {
    element_type* temp;
    int i;
    if (FIFO_buf->count == 0) {
        printf("The FIFO is empty\n");
    } else {
        temp = FIFO_buf->tail;
        for (i = 0; i < FIFO_buf->count; i++) {
					printf("name:%s %s\n gpa :%f \n courses  %d %d %d %d\n",(*temp).fname ,(*temp).lname,(*temp).GPA ,(*temp).SUBJECTS[0],(*temp).SUBJECTS[1],(*temp).SUBJECTS[2],(*temp).SUBJECTS[3]);
            if (temp == FIFO_buf->base + ((FIFO_buf->length) * sizeof(element_type)))
                temp = FIFO_buf->base;
            else
                temp++;
        }
    }
}
void add_student_file(FIFO_buf_t* students_data) {
    FILE *file = fopen("database.txt", "r");
    if (file == NULL) {
        printf("Could not open file\n");
        return;
    }

    element_type student;
    while (fscanf(file, "%d %s %s %f %d %d %d %d", 
                  &student.roll, student.fname, student.lname, &student.GPA, 
                  &student.SUBJECTS[0], &student.SUBJECTS[1], &student.SUBJECTS[2], &student.SUBJECTS[3]) == 8) {
        if (find(students_data,student.roll)==FIFO_null)
        {if (FIFO_enqueue(students_data, student) == FIFO_full) {
            printf("FIFO buffer is full. Could not add more students.\n");
            break;
        }}
        else   printf("cant add %s another with the same roll number exist\n",student.fname);


    }

    fclose(file);
    printf("Students added from file successfully.\n");
}

void add_student_manually(FIFO_buf_t* students_data){
	element_type x;

	printf("enter student roll number ,first name , second name , gpa \n");
	scanf("%d %s %s %f",&x.roll,x.fname,x.lname,&x.GPA);
	printf("enter the student Courses id \n");int i;
	for (i=0;i<4;i++)
	scanf("%d",&x.SUBJECTS[i]);
    if (find(students_data,x.roll)==FIFO_null)
        FIFO_enqueue(students_data, x);
    else {
 printf("cant add %s another with the same roll number exist\n",x.fname);    }


}

FIFO_buf_status find_rl(FIFO_buf_t* students_data){
	printf("enter student roll number \n");
	int id;
	scanf("%d",&id);
	element_type* temp;
		int i;
		if (students_data->count==0){
			printf("the list is empty ");
            return FIFO_empty;
		}
		else temp=students_data->tail;
		for (i=0;i<students_data->count;i++)
		{
			if ((temp)->roll==id)
			{
				printf("name:%s %s\n gpa :%f \n courses  %d %d %d %d\n",(*temp).fname ,(*temp).lname,(*temp).GPA ,(*temp).SUBJECTS[0],(*temp).SUBJECTS[1],(*temp).SUBJECTS[2],(*temp).SUBJECTS[3]);
				return FIFO_no_error;
			}
			if (temp==students_data->base+ ((students_data->length) * sizeof(element_type) ))
				temp=students_data->base;
			else temp++;
		}
		printf("No student with this roll number ");
        return FIFO_null;
}
void find_fn(FIFO_buf_t* students_data){
	printf("enter student first name  \n");
		char name[20];
		scanf("%s",name );
		element_type* temp;
			int i;
			if (students_data->count==0){
				printf("the list is empty ");
			}
			else temp=students_data->tail;
			char ok=0;
			for (i=0;i<students_data->count;i++)
			{
				if (strcmp((*temp).fname,name )==0)
				{
					printf("name:%s %s\n gpa :%f \n courses  %d %d %d %d\n",(*temp).fname ,(*temp).lname,(*temp).GPA ,(*temp).SUBJECTS[0],(*temp).SUBJECTS[1],(*temp).SUBJECTS[2],(*temp).SUBJECTS[3]);
					ok=1;
				}
				if (temp==students_data->base+ ((students_data->length) * sizeof(element_type) ))
					temp=students_data->base;
				else temp++;
			}
			if (ok==0){
			printf("No student with this name  ");}
}
void find_c(FIFO_buf_t* students_data){
	printf("enter course number \n");
		int id;
		scanf("%d",&id);
		element_type* temp;
			int i;
			if (students_data->count==0){
				printf("the list is empty ");
			}
			else temp=students_data->tail;
			char ok=0;
			for (i=0;i<students_data->count;i++)
			{
				int j=0;
				for (j=0;j<4;j++)
				if ((*temp).SUBJECTS[j]==id)
				{
					printf("name:%s %s\n gpa :%f \n courses  %d %d %d %d\n",(*temp).fname ,(*temp).lname,(*temp).GPA ,(*temp).SUBJECTS[0],(*temp).SUBJECTS[1],(*temp).SUBJECTS[2],(*temp).SUBJECTS[3]);
					ok=1;
				}
				if (temp==students_data->base+ ((students_data->length) * sizeof(element_type) ))
					temp=students_data->base;
				else temp++;
			}
			if (!ok)
			printf("No student enroll in this course ");
}
void tot_s(FIFO_buf_t* students_data){
	printf("Number of students enrolled %d\n",students_data->count);
}
#include <stdio.h>
#include "fifo.h"

void del_s(FIFO_buf_t* students_data) {
    if (students_data->count == 0) {
        printf("The list is empty\n");
        return;
    }

    int roll_number;
    printf("Enter the roll number of the student to delete: ");
    scanf("%d", &roll_number);

    element_type* temp = students_data->tail;
    element_type* previous = NULL;
    int i;
    int found = 0;
    for (i = 0; i < students_data->count; i++) {
        if (temp->roll == roll_number) {
            found = 1;
            break;
        }
        previous = temp;
        if (temp == students_data->base + ((students_data->length - 1) * sizeof(element_type))) {
            temp = students_data->base;
        } else {
            temp++;
        }
    }

    if (!found) {
        printf("No student with this roll number\n");
        return;
    }
    while (i < students_data->count - 1) {
        element_type* next = (temp == students_data->base + ((students_data->length - 1) * sizeof(element_type))) ? students_data->base : temp + 1;
        *temp = *next;
        temp = next;
        i++;
    }
    if (students_data->head == students_data->base) {
        students_data->head = students_data->base + ((students_data->length - 1) * sizeof(element_type));
    } else {
        students_data->head--;
    }
    students_data->count--;

    printf("Student with roll number %d deleted successfully\n", roll_number);
}

void up_s(FIFO_buf_t* students_data){
	printf("enter student roll number \n");
		int id;
		scanf("%d",&id);
		element_type* temp;
			int i;
			if (students_data->count==0){
				printf("the list is empty ");
			}
			else temp=students_data->tail;
			for (i=0;i<students_data->count;i++)
			{
				if ((*temp).roll==id)
				{
					printf("name:%s %s\n gpa :%f \n courses  %d %d %d %d\n",(*temp).fname ,(*temp).lname,(*temp).GPA ,(*temp).SUBJECTS[0],(*temp).SUBJECTS[1],(*temp).SUBJECTS[2],(*temp).SUBJECTS[3]);
					printf("wanna to edit\n 1)first name\n2)second name\n3)gpa\n");
					int k=0;
					scanf("%d",&k);
					if (k==1)
					{
						scanf("%s",(*temp).fname );
					}
					else if (k==2)
					{
						scanf("%s",(*temp).lname);
					}
					else if (k==3)
					{
						scanf("%f",&(*temp).GPA);
					}else printf("not vaild choice \n");
					return;
				}
				if (temp==students_data->base + ((students_data->length) * sizeof(element_type) ))
					temp=students_data->base;
				else temp++;
			}
			printf("No student with this roll number ");
}
void show_s(FIFO_buf_t* students_data){
	FIFO_print(students_data);
}

int choice;
int main() {
    FIFO_buf_t students_data;

    if (FIFO_init(&students_data, students_buffer, 20) == FIFO_no_error)
        printf("FIFO init ---done ----\n");

    printf("Welcome to Our Student Management System\n");
    while (1) {
        printf("Choose The Task that you want to perform\n");
        printf("1. Add the Student Details Manually\n");
        printf("2. Add the Student Details From Text File\n");
        printf("3. Find the Student Details by Roll Number\n");
        printf("4. Find the Student Details by First Name\n");
        printf("5. Find the Student Details by Course Id\n");
        printf("6. Find the Total number of Students\n");
        printf("7. Delete the Students Details by Roll Number\n");
        printf("8. Update the Students Details by Roll Number\n");
        printf("9. Show all information\n");
        printf("10. To Exit\n");
        printf("Enter your choice to perform the task:");
        scanf("%d", &choice);
        printf("=======================================\n\n");

        switch (choice) {
            case 1:
                add_student_manually(&students_data);
                printf("----------------------------\n");
                tot_s(&students_data);
                break;
            case 2:
                add_student_file(&students_data);
                printf("----------------------------\n");
                tot_s(&students_data);
                break;
            case 3:
                find_rl(&students_data);
                break;
            case 4:
                find_fn(&students_data);
                break;
            case 5:
                find_c(&students_data);
                break;
            case 6:
                tot_s(&students_data);
                break;
            case 7:
                del_s(&students_data);
                break;
            case 8:
                up_s(&students_data);
                break;
            case 9:
                tot_s(&students_data);
                show_s(&students_data);
                
                break;
            case 10:
                printf("System Terminated...");
                break;
            default:
                printf("Please choose a valid option\n\n");
        }
        if (choice == 10) break;
    }
    return 0;
}