#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
/*#include <>*/
#define LINE_LEN 128

int main(void)
{
    char buf[LINE_LEN];
    pid_t pid;
    int status;

    printf("->:");
    while(fgets(buf,LINE_LEN,stdin)!= NULL)
    {
        if(*buf!='\0')
            buf[strlen(buf)-1]='\0';
        if(strlen(buf)==0)
        {
            printf("->:");
            continue;   
        }
    switch (pid=fork()){
        case -1 :
            perror("fork failed");
            break;
        case 0 :
            /*child process*/
            execlp(buf,buf,NULL);
            perror("cannot exec ");
            break;
        default :
            /*parent process*/
            if(waitpid(pid,&status,0)==-1)
                perror("waitpid");
            break;
    }
    printf("->:");
}
    return 0;
}
