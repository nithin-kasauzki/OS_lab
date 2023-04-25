#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

struct student
{
    int roll;
    int mark[5];
};

int main()
{

    key_t key = ftok("shmfile", 65);

    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    struct student *s1 = (struct student *)shmat(shmid, (void *)0, 0);

    int p = fork();
    if (p == 0)
    {
        // get data
        int temp;
        printf("roll:");
        scanf("%d", &temp);
        s1->roll = temp;
        for (int i = 0; i < 5; i++)
        {
            printf("\nmark %d:", i + 1);
            scanf("%d", &s1->mark[i]);
        }

        // exit(0);
    }
    else if (p > 0)
    {
        wait(NULL);
        float avg = 0;
        for (int i = 0; i < 5; i++)
        {
            avg += s1->mark[i];
        }
        printf("\n tOTAL %d, Average is %.2f\n", avg, avg / 5.0);
    }
    shmdt(s1);
    return 0;
}