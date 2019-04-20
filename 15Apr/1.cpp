// Reader-Writer Problem

#include<iostream>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
using namespace std;

sem_t wrt, mutex;
int readcount = 0;

void *writer(void *arg)
{
    sem_wait(&wrt);
    cout<<"Write\n";
    sem_post(&wrt);
}

void *reader(void *arg)
{
    sem_wait(&mutex);
    readcount++;
    if(readcount == 1)
        sem_wait(&wrt);
    sem_post(&mutex);
    cout<<"Read\n";
    sem_wait(&mutex);
    readcount--;
    if(readcount == 0)
        sem_post(&wrt);
    sem_post(&mutex);
}

int main(int argc, char const *argv[])
{
    pthread_t a[5];
    sem_init(&wrt, 0, 1);
    sem_init(&mutex, 0, 1);
    for(int i = 0; i < 3; i++)
        pthread_create(&a[i], NULL, reader, NULL);
    for(int i = 3; i < 5; i++)
        pthread_create(&a[i], NULL, writer, NULL);
    sleep(2);
    pthread_join(a[0], NULL);
    pthread_join(a[1], NULL);
    pthread_join(a[2], NULL);
    sleep(2);
    pthread_join(a[0], NULL);
    pthread_join(a[3], NULL);
    sleep(2);
    pthread_join(a[3], NULL);
    pthread_join(a[4], NULL);
    sem_destroy(&wrt);
    sem_destroy(&mutex);
    return 0;
}
