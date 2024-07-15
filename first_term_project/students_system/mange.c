

#include "mange.h"
#include "fifo.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fifo.h"

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