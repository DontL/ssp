#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define LINE_LEN 255

/*
 *for signal 
 */
#include <signal.h>
#include <errno.h>

static void sigint(int sig);

int main(void)
{
    char buf[LINE_LEN];
    pid_t pid;
    int status;

 if(sigset(SIGINT, sigint)== SIG_ERR) 
   perror("sigint"); 

    printf("->:");
    
    for(;;)
    {
        while(fgets(buf,LINE_LEN,stdin)!=NULL)
        {
            if(*buf != '\0')
                buf[strlen(buf)-1]='\0';
            printf("->:");
            continue;
        }
        
    switch (pid = fork()){
        case -1:
            perror("fork failed");
            break;
        case 0:
            execlp(buf,buf,NULL);
            perror("cannot execlp");
            break;
        default :
            if(waitpid(pid,&status,0)==-1)
                perror("waitpid");
                break;
    }
    printf("->:");
    
    if(errno != EINTR)
        break;
    errno = 0;
    }
    return (0);
}

static void sigint(int sig)
{
    printf("Caught SIGINT\n");
    printf("->:");
}
