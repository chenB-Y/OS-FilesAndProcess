// חן חזיזה   319027892
//שחר נעים 318685807
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
# include <sys/fcntl.h>
#include <string.h>
#include <stdlib.h>
# include<unistd.h>
int checkLine(char* file);
int placeOfMark = 0;
int main(int argc, char* argv[])
{
    int fdo, dfr1, dfs1, dfr2, dfr3, counter = 0, numOfLet, fdf1, fdf2, fdf3, fde, fde9, fdres, fdop, fdin, stat, fdww, f, rid, lsk;
    char ch, ch1, ch2, ch3;
    char temp[10] = "/main.exe";
    char cmdn[40] = "./allStudents/";
    char arrPlacezero[40];
    char* arr[3];
    arr[1] = "input.txt";
    arr[2] = NULL;
    char* cmdc = "./comp.out";
    char* argr[4];
    argr[0] = "comp.out";
    argr[1] = "output.txt";
    argr[2] = "expectedOutput.txt";
    argr[3] = NULL;
    char* cmd = "ls";
    if (argc != 2)
        exit(0);
    fdo = open(argv[1], O_RDONLY);
    if (fdo < 0)
        exit(0);
    dfs1 = lseek(fdo, placeOfMark, SEEK_SET);
    numOfLet = checkLine(argv[1]);
    char* dir = (char*)malloc((numOfLet + 1) * sizeof(char));
    dfr1 = read(fdo, dir, numOfLet);
    dfs1 = lseek(fdo, placeOfMark, SEEK_SET);
    numOfLet = checkLine(argv[1]);
    char* in = (char*)malloc((numOfLet + 1) * sizeof(char));
    dfr1 = read(fdo, in, numOfLet);
    dfs1 = lseek(fdo, placeOfMark, SEEK_SET);
    numOfLet = checkLine(argv[1]);
    char* out = (char*)malloc((numOfLet + 1) * sizeof(char));
    dfr1 = read(fdo, out, numOfLet);
    close(fdo);
    fdf1 = fork();
    if (fdo < 0)
        exit(0);
    if (fdf1 == 0)
    {
        fdo = open("studentList.txt", O_CREAT | O_WRONLY, 777);
        if (fdo < 0)
            exit(0);
        close(1);
        dup(fdo);
        close(fdo);
        char* args[3] = { "ls",dir, NULL };
        fde = execvp(cmd, args);
        close(fdo);
        if (fde < 0)
            exit(0);
    }
    else
        wait(NULL);
    fdres = open("result.csv", O_CREAT | O_WRONLY, 777);
    if (fdres < 0)
        exit(0);
    fdo = open("studentList.txt", O_RDONLY);
    if (fdo < 0)
        exit(0);
    else
        placeOfMark = 0;
    while ((dfr1 = read(fdo, &ch, 1)) > 0)
    {
        dfs1 = lseek(fdo, placeOfMark, SEEK_SET);
        numOfLet = checkLine("studentList.txt");
        char* student = (char*)malloc((numOfLet + 1) * sizeof(char));
        dfr1 = read(fdo, student, numOfLet);
        char* ff = (char*)malloc(30 * sizeof(char));
        strcpy(ff, cmdn);
        strcat(ff, student);
        strcat(ff, temp);
        arr[0] = ff;
        if (dfr1 = read(fdo, &ch, 1) < 1)
            break;
        fdf2 = fork();
        if (fdf2 < 0)
            exit(0);
        if (fdf2 == 0)
        {
            fdop = open("output.txt", O_CREAT | O_RDWR);
            if (fdop < 0)
                exit(0);
            close(1);
            dup(fdop);
            close(fdop);
            execvp(ff, arr);
            return 0;
        }
        else
            wait(NULL);
        fdf3 = fork();
        if (fdf3 < 0)
        {
            exit(0);
        }
        if (fdf3 == 0)
        {
            fde9 = execvp(cmdc, argr);
        }
        else
            wait(&stat);
        if (stat == 2 || stat == 512)
        {
            f = fork();
            if (f == 0)
            {
                close(1);
                dup(fdres);
                close(fdres);
                printf("%s  100\n", student);
                return 0;
            }
            else
                wait(NULL);

        }
        else if (stat == 1 || stat == 256)
        {
            f = fork();
            if (f == 0)
            {
                close(1);
                dup(fdres);
                close(fdres);
                printf("%s  0\n", student);
                return 0;
            }
            else
                wait(NULL);
        }
        free(student);
        free(ff);
    }
    free(dir);
    free(in);
    free(out);
    exit(0);
}
int checkLine(char* file) {
    int dfo, dfr, dfls, counter = 0;
    char ch;
    dfo = open(file, O_RDONLY);
    if (dfo < 0)
        exit(0);
    dfls = lseek(dfo, placeOfMark, SEEK_SET);
    if (dfls < 0)
        return 0;
    while (1)
    {
        dfr = read(dfo, &ch, 1);
        counter++;
        if (ch == '\n')
            break;
    }
    placeOfMark += counter;
    close(dfo);
    return (counter - 1);
}
