#include <bits/stdc++.h>

using namespace std;

void FirstFit()
{

    int partitions[] = {300, 650, 450, 500, 800};
    int n = sizeof(partitions) / sizeof(partitions[0]);
    int processes[] = {412, 517, 372, 626};
    int m = sizeof(processes) / sizeof(processes[0]);
    int allocation[m];
    cout << "partitions:";
    for (int i = 0; i < n; i++)
    {
        cout << partitions[i] << "\t";
    }
    cout << "\n\n\t FIRST FIT\n";
    memset(allocation, -1, sizeof(allocation));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (partitions[j] >= processes[i])
            {
                allocation[i] = j;
                partitions[j] -= processes[i];
                break;
            }
        }
    }

    cout << "Process No.\tProcess Size\tPartition No.\n";
    for (int i = 0; i < m; i++)
    {
        cout << i + 1 << "\t\t" << processes[i] << "\t\t";
        if (allocation[i] != -1)
        {
            cout << allocation[i] + 1 << endl;
        }
        else
        {
            cout << "Not Allocated" << endl;
        }
    }
}

void BestFit()
{
    cout << "\n\t Best FIT\n";
    int partitions[] = {300, 650, 450, 500, 800};
    int n = sizeof(partitions) / sizeof(partitions[0]);
    int processes[] = {412, 517, 372, 626};
    int m = sizeof(processes) / sizeof(processes[0]);
    int allocation[m];

    memset(allocation, -1, sizeof(allocation));

    for (int i = 0; i < m; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < n; j++)
        {
            if (partitions[j] >= processes[i])
            {
                if (bestIdx == -1 || partitions[j] < partitions[bestIdx])
                {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
            partitions[bestIdx] -= processes[i];
        }
    }
    cout << "Process No.\tProcess Size\tPartition No.\n";
    for (int i = 0; i < m; i++)
    {
        cout << i + 1 << "\t\t" << processes[i] << "\t\t";
        if (allocation[i] != -1)
        {
            cout << allocation[i] + 1 << endl;
        }
        else
        {
            cout << "Not Allocated" << endl;
        }
    }
}

void WorstFit()
{
    int partitions[] = {300, 650, 450, 500, 800};
    int n = sizeof(partitions) / sizeof(partitions[0]);
    int processes[] = {412, 517, 372, 626};
    int m = sizeof(processes) / sizeof(processes[0]);
    int allocation[m];

    memset(allocation, -1, sizeof(allocation));
    cout << "\n\t Worst Fit\n";
    for (int i = 0; i < m; i++)
    {
        int worstIdx = -1;
        for (int j = 0; j < n; j++)
        {
            if (partitions[j] >= processes[i])
            {
                if (worstIdx == -1 || partitions[j] > partitions[worstIdx])
                {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1)
        {
            allocation[i] = worstIdx;
            partitions[worstIdx] -= processes[i];
        }
    }

    cout << "Process No.\tProcess Size\tPartition No.\n";
    for (int i = 0; i < m; i++)
    {
        cout << i + 1 << "\t\t" << processes[i] << "\t\t";
        if (allocation[i] != -1)
        {
            cout << allocation[i] + 1 << endl;
        }
        else
        {
            cout << "Not Allocated" << endl;
        }
    }
}

int main()
{
    FirstFit();
    BestFit();
    WorstFit();
}