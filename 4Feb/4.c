// Using WIFSIGNALED by making an error

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t cpid;
    int status, pid;
    pid = fork();
    int *p = NULL;
    if(pid == 0)
    {
        if(argc > 1)
            *p = 1; // Intentionally creating segmentation fault to trigger a signal
        printf("Child created successfully, ID: %d\n", getpid());
        _exit(8);
    }
    else
        cpid = wait(&status);
    printf("Parent's PID: %d\n", getpid());
    printf("Child's PID: %d\n", cpid);
    if(WIFEXITED(status))
        printf("Exitted Normally.... Status: %d\n", WEXITSTATUS(status));
    else if(WIFSIGNALED(status))
        printf("Exitted with a signal.... Status: %d\n", WTERMSIG(status));
    
    return 0;
}