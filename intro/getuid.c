#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    printf("USER ID: %ld , Group ID : %ld \n",(long) getuid(),(long) getgid());
    return (0);
}
