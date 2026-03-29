#include <stdio.h>
#include <string.h>
#include "task.h"
#include "task.c"

extern int task_count;
extern Task task_list[MAX_TASKS];

void add_task(const char* title);
void list_tasks();
void complete_task(int id);
void delete_task(int id);
void save_tasks_to_file(const char* filename);
void load_tasks_from_file(const char* filename);

// Main function to run the task manager
int main(){
    char title[MAX_TITLE_LENGTH];
    int choice, id;
    load_tasks_from_file("tasks.txt");

    while (1) {
        printf("\n--- Task Manager ---\n");
        printf("1. Add Task\n");
        printf("2. List Tasks\n");
        printf("3. Mark Task as Done\n");
        printf("4. Delete Task\n");
        printf("5. Save Tasks to File\n");
        printf("6. Load Tasks from File\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter task title: ");
                scanf("%s", title);
                add_task(title);
                break;
            case 2:
                list_tasks();
                break;
            case 3:
                printf("Enter task ID: ");
                scanf("%d", &id);
                complete_task(id);
                break;
            case 4:
                printf("Enter task ID: ");
                scanf("%d", &id);
                delete_task(id);
                break;
            case 5:
                save_tasks_to_file("tasks.txt");
                break;
            case 6:
                load_tasks_from_file("tasks.txt");
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}