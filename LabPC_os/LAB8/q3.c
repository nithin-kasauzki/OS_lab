#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{

    key_t key = ftok("shmfile", 65);

    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    int *n = (int *)shmat(shmid, (void *)0, 0);

    int p = fork();
    if (p == 0)
    {

        int k;
        printf("enter n:");
        scanf("%d", &k);
        *n = k;
        // exit(0);
    }
    else if (p > 0)
    {
        wait(NULL);
        if (*n % 2 != 0)
            printf("\nnumber is %d odd\n", *n);
        else
            printf("\n number is %d even \n", *n);
    }
    shmdt(n);
    return 0;
}