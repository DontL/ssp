#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

<<<<<<< HEAD
int main(int argc,char *argv[])
=======
int main(int argc, char *argv[])
>>>>>>> origin/master
{
    DIR *dir;
    struct dirent *dirent;

    if(argc!=2)
    {
<<<<<<< HEAD
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

=======
        perror("too less paramter .");
        exit(0);
    }   
        if((dir=opendir(argv[1]))==NULL)
        {
            perror("opendir failed");
            exit(0);
        }
    
    while((dirent=readdir(dir))!=NULL)
        printf("%s\n",dirent->d_name);

    closedir(dir);

    return (0);
>>>>>>> origin/master
}
