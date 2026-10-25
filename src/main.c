#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../inc/threadpool.h"

void example_task(void *arg)
{
    int task_id = *(int *)arg;

    printf("Task %d started\n", task_id);

    sleep(1);

    printf("Task %d finished\n", task_id);
}

int main(void)
{
    threadpool_t pool;
    threadpool_init(&pool);

    int task_ids[20];
    for (int i = 0; i < 20; i++)
    {
        task_ids[i] = i + 1;
        threadpool_add_task(&pool, example_task, &task_ids[i]);
    }
    threadpool_destroy(&pool);

    printf("All tasks completed. Thread pool destroyed.\n");
    return 0;
}
