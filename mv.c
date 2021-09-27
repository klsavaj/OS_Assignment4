#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int mv(const char *source, const char *des){
    rename(source,des);
}

int main(int tempC, const char *tempV[])
{
    mv(tempV[1], tempV[2]);
}