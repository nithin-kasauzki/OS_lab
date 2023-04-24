#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main()
{
    pid_t pid2, pid3, pid4, pid5;

    cout << "Process 1 (pid " << getpid() << ", parent pid " << getppid() << ")" << endl;

    pid2 = fork();

    if (pid2 == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0)
    { // child 2
        cout << "Process 2 (pid " << getpid() << ", parent pid " << getppid() << ")" << endl;

        pid4 = fork();

        if (pid4 == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid4 == 0)
        { // child 4
            cout << "Process 4 (pid " << getpid() << ", parent pid " << getppid() << ")" << endl;
        }
        else
        {               // parent of 4 (child 2)
            wait(NULL); // wait for child 4 to terminate
        }

        exit(EXIT_SUCCESS);
    }
    else
    { // parent of 2 (process 1)
        pid3 = fork();

        if (pid3 == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid3 == 0)
        { // child 3
            cout << "Process 3 (pid " << getpid() << ", parent pid " << getppid() << ")" << endl;

            pid5 = fork();

            if (pid5 == -1)
            {
                perror("fork");
                exit(EXIT_FAILURE);
            }

            if (pid5 == 0)
            { // child 5
                cout << "Process 5 (pid " << getpid() << ", parent pid " << getppid() << ")" << endl;
            }
            else
            {               // parent of 5 (child 3)
                wait(NULL); // wait for child 5 to terminate
            }

            exit(EXIT_SUCCESS);
        }
        else
        {               // parent of 3 (process 1)
            wait(NULL); // wait for child 2 to terminate
            wait(NULL); // wait for child 3 to terminate
            exit(EXIT_SUCCESS);
        }
    }
}
