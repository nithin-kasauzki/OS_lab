#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_ITEMS 1

int balance = 0;

sem_t deposit_sem, withdraw_sem;

void *producer(void *arg)
{
    int item, i;

    for (i = 0; i < MAX_ITEMS; i++)
    {
        item = 5000;

        sem_wait(&deposit_sem);

        balance += item;

        printf("Producer deposited Rs.%d. Current balance: Rs.%d\n", item, balance);

        sem_post(&withdraw_sem);
    }

    pthread_exit(NULL);
}

void *consumer(void *arg)
{
    int item, i;

    for (i = 0; i < MAX_ITEMS; i++)
    {
        sem_wait(&withdraw_sem);

        item = 2000;

        if (balance >= item)
        {
            balance -= item;

            printf("Consumer withdrew Rs.%d. Current balance: Rs.%d\n", item, balance);

            sem_post(&deposit_sem);
        }
        else
        {
            printf("Consumer could not withdraw Rs.%d. Current balance: Rs.%d\n", item, balance);

            sem_post(&withdraw_sem);
        }
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t prod_thread, cons_thread;

    sem_init(&deposit_sem, 0, 1);
    sem_init(&withdraw_sem, 0, 0);

    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    sem_destroy(&deposit_sem);
    sem_destroy(&withdraw_sem);

    return 0;
}