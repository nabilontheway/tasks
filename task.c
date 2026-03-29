#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"

int task_count = 0;
Task task_list[MAX_TASKS];

/* Function to add a new task */
void add_task(const char* title){
    if (task_count >= MAX_TASKS) {
        printf("Task list is full. Cannot add more tasks.\n");
        return;
    }
    
    task_list[task_count].id = task_count + 1; // Assign a unique ID to the task
    strncpy(task_list[task_count].title, title, MAX_TITLE_LENGTH - 1);
    task_list[task_count].title[MAX_TITLE_LENGTH - 1] = '\0';
    task_list[task_count].completed = 0; // Mark the task as not completed
    task_count++;
    printf("Task added: %s\n", title);
}

/* Function to list all tasks */
void list_tasks(){
    if (task_count == 0) {
        printf("No tasks to display.\n");
        return;
    }
    
    printf("Task List:\n");
    for (int i = 0; i < task_count; i++) {
        printf("%d. [%s] %s\n", task_list[i].id, task_list[i].completed ? "X" : " ", task_list[i].title);
    }
}

/* Function to complete a task by its ID */
void complete_task(int id){
    for (int i = 0; i < task_count; i++) {
        if (task_list[i].id == id) {
            task_list[i].completed = 1; // Mark the task as completed
            printf("Task completed: %s\n", task_list[i].title);
            return;
        }
    }
    printf("Task with ID %d not found.\n", id);
}

/* Function to delete a task by its ID */
void delete_task(int id){
    for (int i = 0; i < task_count; i++) {
        if (task_list[i].id == id) {
            // Shift tasks down to fill the gap
            for (int j = i; j < task_count - 1; j++) {
                task_list[j] = task_list[j + 1];
            }
            task_count--; // Decrease the task count
            printf("Task with ID %d deleted.\n", id);
            return;
        }
    }
    printf("Task with ID %d not found.\n", id);
}


/* File IO functions */
/* Function to save tasks to a file */
void save_tasks_to_file(const char* filename){
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }
    for (int i = 0; i < task_count; i++) {
        fprintf(file, "%d,%s,%d\n", task_list[i].id, task_list[i].title, task_list[i].completed);
    }
    fclose(file);
    printf("Tasks saved to file: %s\n", filename);
}

/* Function to load tasks from a file */
void load_tasks_from_file(const char* filename){
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file for reading.\n");
        return;
    }
    task_count = 0;
    while (task_count < MAX_TASKS) {
        Task t;
        if (fscanf(file, "%d,%[^,],%d\n", &t.id, t.title, &t.completed) != 3) {
            break;
        }
        task_list[task_count] = t;
        task_count++;
    }
    fclose(file);
    printf("Tasks loaded from file: %s\n", filename);
}


