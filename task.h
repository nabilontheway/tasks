#ifndef TASK_H
#define TASK_H

#define MAX_TITLE_LENGTH 100
#define MAX_TASKS 100

/* Define Task struct here in case task.h doesn't define it.
   This uses MAX_TITLE_LENGTH which is expected to be in task.h. */
typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    int completed;
}Task;
#endif