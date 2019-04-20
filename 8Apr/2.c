// Semaphores

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t s;
void *fun(int *arg)
{
    sem_wait(&s);
    printf("Executing critical section with PID: %d\n", (int)arg);
    sem_post(&s);
}

int main(int argc, char const *argv[])
{
    pthread_t a[2];
    sem_init(&s, 0, 1);
    int i;
    for(i = 0; i < 2; i++)
        pthread_create(&a[i], NULL, fun, (void *)i);
    for(i = 0; i < 2; i++)
        pthread_join(a[i], NULL);
    sem_destroy(&s);
    return 0;
}
