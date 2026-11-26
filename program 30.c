
#include <stdio.h>
#include <pthread.h>

void *fun(void *arg)
{
    printf("Thread is created successfully.\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t t1;

    pthread_create(&t1, NULL, fun, NULL);

    pthread_join(t1, NULL);

    printf("Main thread completed.\n");

    return 0;
}

