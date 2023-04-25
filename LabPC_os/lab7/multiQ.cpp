#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct process
{
    string name;
    int arrival_time;
    int cpu_burst_time;
    int queue_number;
    int waiting_time;
    int turnaround_time;
};

int main()
{

    process processes[] = {
        {"p1", 0, 4, 1, 0, 4},
        {"p2", 0, 3, 1, 4, 7},
        {"p3", 10, 8, 2, 12, 20},
        {"p4", 0, 5, 1, 0, 5}};
    int num_processes = sizeof(processes) / sizeof(process);

    queue<process> q1, q2;

    for (int i = 0; i < num_processes; i++)
    {
        process p = processes[i];
        if (p.queue_number == 1)
        {
            q1.push(p);
        }
        else
        {
            q2.push(p);
        }
    }

    int clock = 0;
    int idle_time = 0;

    int quantum = 2;
    int time_slice = quantum;

    cout << "Gantt Chart:" << endl;
    while (!q1.empty() || !q2.empty())
    {

        if (!q1.empty())
        {
            process p = q1.front();
            q1.pop();
            cout << p.name << " ";
            if (p.cpu_burst_time <= time_slice)
            {
                clock += p.cpu_burst_time;
                time_slice -= p.cpu_burst_time;
                p.turnaround_time = clock - p.arrival_time;
                p.waiting_time = p.turnaround_time - p.cpu_burst_time;
            }
            else
            {
                clock += time_slice;
                idle_time += clock - p.arrival_time;
                p.cpu_burst_time -= time_slice;
                q2.push(p);
                time_slice = quantum;
            }
        }

        else if (!q2.empty())
        {
            process p = q2.front();
            q2.pop();
            cout << p.name << " ";
            clock += p.cpu_burst_time;
            p.turnaround_time = clock - p.arrival_time;
            p.waiting_time = p.turnaround_time - p.cpu_burst_time;
        }
    }
    cout << endl;

    cout << "Process\tArrival Time\tBurst Time\tQueue Number\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < num_processes; i++)
    {
        process p = processes[i];
        cout << p.name << "\t" << p.arrival_time << "\t\t" << p.cpu_burst_time << "\t\t" << p.queue_number << "\t\t" << p.waiting_time << "\t\t" << p.turnaround_time << endl;
    }

    return 0;
}
