#include <stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char* argv[])
{
    int dfo1, dfo2;
    char ch1, ch2;
    int dfr1, dfr2;
    dfo1 = open(argv[1], O_RDONLY);
    if (dfo1 < 0)
        exit(1);
    dfo2 = open(argv[2], O_RDONLY);
    if (dfo2 < 0)
        exit(1);
    while (1)
    {
        dfr1 = read(dfo1, &ch1, 1);
        if (dfr1 < 0)
            exit(1);
        dfr2 = read(dfo2, &ch2, 1);
        if (dfr2 < 0)
            exit(1);
        if (dfr1 == 0 && dfr2 == 0)
            exit(2);
        if (dfr1 != dfr2)
            exit(1);
        if (ch1 != ch2)
            exit(1);
    }
}

