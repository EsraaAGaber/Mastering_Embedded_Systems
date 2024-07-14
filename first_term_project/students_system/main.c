#include "fifo.h"
#include "mange.h"
#include "stdio.h"

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
