#include <iostream>
// Child process read N characters and puts in to the pipe and
// Parent process reads and finds total no of vowels.
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
int main()
{
    char Buffer[20];
    int fd[2];
    pipe(fd);
    int p;
    p = fork();
    if (p == 0)
    {
        close(fd[0]);
        fgets(Buffer, 20, stdin);
        write(fd[1], Buffer, 20);
        close(fd[1]);
        exit(0);
    }
    else
    {
        wait(NULL);
        close(fd[1]);
        read(fd[0], Buffer, 20);
        for (int i = 0; i < 20; i++)
        {
            if (Buffer[i] == 'a' || Buffer[i] == 'e' || Buffer[i] == 'i' || Buffer[i] == 'o')
            {
                cout << Buffer[i];
            }
        }
        close(fd[0]);
        exit(0);
    }
}