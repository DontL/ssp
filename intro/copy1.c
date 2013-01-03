#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#define BUFFSIZ 256

int main(void)
{
    ssize_t n;
    ssize_t res;
    char buf[BUFFSIZ];
    char *ptr;

    while((n=read(STDIN_FILENO,buf,BUFFSIZ))>0)
    {
        ptr = buf;
        while((n>0)&&((res=write(STDOUT_FILENO,ptr,n))>0))
        {
            ptr += res;
            n -= res;
        }
        if(res == -1)
            perror("write failed");
    }
    if(n == -1)
        perror("read failed");
    return 0;
}
