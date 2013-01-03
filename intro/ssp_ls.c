#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    DIR *dir;
    struct dirent *dirent;

    if(argc!=2)
    {
        perror("Usage:too few parameters ");
        exit(0);
    }
    if((dir=opendir(argv[1]))==NULL)
    {
        perror("Cannot open");
        exit(0);
    }
    while((dirent=readdir(dir))!=NULL)
        printf("%s\n",dirent->d_name);
    closedir(dir);
    return (0);

}
