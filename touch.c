#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    const char *f1="touch.txt";
    int temp=open(f1,O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if(temp==-1)
    {
        const char *str="Ooops....Don't able to create file.\n";
        write(2,str,200);
    }
    return 0;
}