#include <iostream>
#include <vector>
using namespace std;

struct process
{
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

int main()
{
    int n = 5; // number of processes
    int quantum_time = 2;

    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    // Initialize processes
    process processes[] = {{2, 12, 12, 0, 0},
                           {0, 2, 2, 0, 0},
                           {1, 3, 3, 0, 0},
                           {3, 7, 7, 0, 0},
                           {5, 11, 11, 0, 0}};

    // Implement Round Robin algorithm
    int current_time = 0;
    bool done = false;
    while (!done)
    {
        done = true;
        for (int i = 0; i < n; i++)
        {
            if (processes[i].remaining_time > 0)
            {
                done = false;
                if (processes[i].remaining_time > quantum_time)
                {
                    current_time += quantum_time;
                    processes[i].remaining_time -= quantum_time;
                }
                else
                {
                    current_time += processes[i].remaining_time;
                    processes[i].waiting_time = current_time - processes[i].burst_time - processes[i].arrival_time;
                    processes[i].remaining_time = 0;
                    processes[i].turnaround_time = current_time - processes[i].arrival_time;
                    total_waiting_time += processes[i].waiting_time;
                    total_turnaround_time += processes[i].turnaround_time;
                }
            }
        }
    }

    // Display results in table format
    cout << "Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t\t" << processes[i].arrival_time << "\t\t" << processes[i].burst_time << "\t\t" << processes[i].waiting_time << "\t\t" << processes[i].turnaround_time << "\n";
    }
    double avg_waiting_time = (double)total_waiting_time / n;
    double avg_turnaround_time = (double)total_turnaround_time / n;
    cout << "Average Waiting Time: " << avg_waiting_time << "\n";
    cout << "Average Turnaround Time: " << avg_turnaround_time << "\n";
    return 0;
}
