#ifndef TASK_H
#define TASK_H

#define MAX_TITLE_LENGTH 100
#define MAX_TASKS 100

struct Task {
    int id;
    char title[MAX_TITLE_LENGTH];
    int completed;
}Task;
#endif