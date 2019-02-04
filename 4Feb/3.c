// Using waitpid() 

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    pid_t a[2];
    int pid, status, i;
    for(i = 0; i < 2; i++)
    {
        a[i] = fork();
        if(a[i] == 0)
            _exit(i+5);
    }
    for(int i = 0; i < 2; i++)
    {
        pid_t temp = waitpid(a[i], &status, 0);
        if (WIFEXITED(status)) 
            printf("Child %d terminated with status: %d\n", temp, WEXITSTATUS(status)); 
    }
    
    return 0;
}