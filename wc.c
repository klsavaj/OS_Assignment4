#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int i, cCount = 0, lCount = 0, wCount = 0, temp;
    char buf[BUFSIZ];
    temp = open("fifu.txt", O_RDONLY);
    if (temp == -1)
    {
        perror("Error in opening the file");
        exit(1);
    }
    else
    {
        while (i = read(temp, buf, 1) > 0)
        {
            cCount++;
            if (buf[0] == ' ')
                wCount++;

            if (buf[0] == '\n')
                lCount++;
        }
        printf("%d %d %d", cCount, wCount + 1, lCount);
        close(temp);
    }
    return 0;
}