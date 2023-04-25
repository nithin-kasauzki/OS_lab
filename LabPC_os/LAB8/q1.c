
#include <stdio.h>
#include <stdlib.h>

int mutex = 1;

int full = 0;

int balance = 0;
int empty = 10, x = 0;
int wait(int s)
{
    return (--s);
}

int signal(int s)
{
    return (++s);
}

void producer(int amount)
{

    mutex = wait(mutex);
    full = signal(full);

    empty = wait(empty);
    balance += amount;
    x++;
    // printf("\n amount = %d",amount);

    printf("\nYour bank balance %d", balance);

    mutex = signal(mutex);
}

void consumer(int amount)
{

    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    balance -= amount;
    printf("\nYour bank balance %d", balance);

    x--;
    mutex = signal(mutex);
}

int main()
{
    int n, i, amount;
    printf("\n1. Press 1 for Deposit"
           "\n2. Press 2 for Withdraw"
           "\n3. Press 3 for Exit");

    // #pragma omp critical

    for (i = 1; i > 0; i++)
    {

        printf("\nEnter your choice:");
        scanf("%d", &n);

        switch (n)
        {
        case 1:

            if ((mutex == 1) && (empty != 0))
            {
                amount = 5000;
                producer(amount);
            }
            else
            {
                printf("Buffer is full!");
            }
            break;

        case 2:
            if ((mutex == 1) && (balance > 2000))
            {
                amount = 2000;
                consumer(amount);
            }

            else
            {
                printf("not possible!");
            }
            break;

        case 3:
            exit(0);
            break;
        }
    }
}