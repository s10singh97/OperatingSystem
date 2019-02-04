// Using wait()

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    int pid, status;
    pid = fork();
    if(pid == -1)
    {
        printf("Child creation Unsuccessful\n");
        _exit(5);
    }
    else if (pid == 0) {
        printf("Child creation successful\n");
    }
    else
    {
        wait(&status);
        printf("Parent process created\n");
    }    
    return 0;
}