// Semaphores

#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
#include<sys/types.h>
#include<fcntl.h>
using namespace std;
sem_t s;
void *fun(void *arg)
{
    sem_wait(&s);
    cout<<"Executing critical section\n";
    sem_post(&s);
}

int main(int argc, char const *argv[])
{
    pthread_t a, b;
    sem_init(&s, 0, 1);
    pthread_create(&a, NULL, fun, NULL);
    pthread_create(&b, NULL, fun, NULL);
    pthread_join(a, NULL);
    pthread_join(b, NULL);
    sem_destroy(&s);
    return 0;
}
