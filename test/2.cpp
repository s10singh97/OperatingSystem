#include<iostream>
#include<pthread.h>
#include<semaphore.h>
using namespace std;

sem_t chopstick[5];

void * fun(void * arg)
{
    int i = int(long(arg));
    sem_wait(&chopstick[i%5]);
    sem_wait(&chopstick[(i+1)%5]);
    cout<<i+1<<" Eating\n";
    sem_post(&chopstick[i%5]);
    sem_post(&chopstick[(i+1)%5]);
}

void * fun1(void * arg)
{
    int i = int(long(arg));
    sem_wait(&chopstick[(i+1)%5]);
    sem_wait(&chopstick[i%5]);
    cout<<i+1<<" Eating\n";
    sem_post(&chopstick[i%5]);
    sem_post(&chopstick[(i+1)%5]);
}

int main(int argc, char const *argv[])
{
    pthread_t phil[5];
    for(int i = 0; i < 5; i++)
        sem_init(&chopstick[i], 0, 1);
    for(int i = 0; i < 3; i++)
        pthread_create(&phil[i], NULL, fun, (void *)i);
    pthread_create(&phil[3], NULL, fun1, (void *)3);
    pthread_create(&phil[4], NULL, fun, (void *)4);

    for(int i = 0; i < 5; i++)
        pthread_join(phil[i], NULL);

    for(int i = 0; i < 5; i++)
        sem_destroy(&chopstick[i]);
    return 0;
}
