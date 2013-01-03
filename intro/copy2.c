#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#ifdef BUFSIZ
#undef BUFSIZ
#define BUFSIZ  100
#endif
int main(void)
{
    ssize_t n;
    /*ssize_t */

    char buf[BUFSIZ];

    while((n=read(STDIN_FILENO,buf,BUFSIZ))>0)
    {
        if(n!=write(STDOUT_FILENO,buf,n))
            perror("write error");
    
    }
    if(n<0)
        perror("read error");
    return 0;

}
