#include <iostream>
#include <vector>

using namespace std;

struct process
{
    string name;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void calculate_waiting_time(vector<process> &processes, int quantum)
{
    int n = processes.size();
    vector<int> remaining_time(n);
    for (int i = 0; i < n; i++)
    {
        remaining_time[i] = processes[i].burst_time;
    }

    int clock = 0;
    while (true)
    {
        bool all_finished = true;
        for (int i = 0; i < n; i++)
        {
            if (remaining_time[i] > 0)
            {
                all_finished = false;
                if (remaining_time[i] <= quantum)
                {
                    clock += remaining_time[i];
                    processes[i].waiting_time = clock - processes[i].burst_time - processes[i].arrival_time;
                    remaining_time[i] = 0;
                }
                else
                {
                    clock += quantum;
                    remaining_time[i] -= quantum;
                }
            }
        }
        if (all_finished)
        {
            break;
        }
    }
}

void calculate_turnaround_time(vector<process> &processes)
{
    for (int i = 0; i < processes.size(); i++)
    {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

void print_table(vector<process> &processes)
{
    int n = processes.size();
    int total_waiting_time = 0, total_turnaround_time = 0;
    cout << "Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; i++)
    {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        cout << processes[i].name << "\t\t" << processes[i].arrival_time << "\t\t" << processes[i].burst_time << "\t\t"
             << processes[i].waiting_time << "\t\t" << processes[i].turnaround_time << endl;
    }
    double avg_waiting_time = (double)total_waiting_time / n;
    double avg_turnaround_time = (double)total_turnaround_time / n;
    cout << "Average waiting time: " << avg_waiting_time << endl;
    cout << "Average turnaround time: " << avg_turnaround_time << endl;
}

int main()
{
    vector<process> processes{
        {"p1", 2, 12, 0, 0},
        {"p2", 0, 2, 0, 0},
        {"p3", 1, 3, 0, 0},
        {"p4", 3, 7, 0, 0},
        {"p5", 5, 11, 0, 0}};

    int quantum = 2;

    calculate_waiting_time(processes, quantum);
    calculate_turnaround_time(processes);
    print_table(processes);

    return 0;
}
