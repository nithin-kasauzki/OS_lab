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
    // define the processes
    process processes[] = {
        {"p1", 0, 4, 1},
        {"p2", 0, 3, 1},
        {"p3", 0, 8, 2},
        {"p4", 10, 5, 1}};
    int num_processes = sizeof(processes) / sizeof(process);

    // create the queues
    queue<process> q1, q2;

    // add processes to their respective queues
    for (int i = 0; i < num_processes; i++)
    {
        if (processes[i].queue_number == 1)
        {
            q1.push(processes[i]);
        }
        else if (processes[i].queue_number == 2)
        {
            q2.push(processes[i]);
        }
    }

    // initialize the clock and idle time
    int clock = 0;
    int idle_time = 0;

    // initialize the quantum and time slice for queue 1
    int quantum = 2;
    int time_slice = quantum;

    // execute the processes in the two queues
    cout << "Gantt Chart:" << endl;
    while (!q1.empty() || !q2.empty())
    {
        // execute the processes in queue 1
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
            // add any new arrivals to queue 1
            for (int i = 0; i < num_processes; i++)
            {
                if (processes[i].queue_number == 1 && processes[i].arrival_time <= clock)
                {
                    q1.push(processes[i]);
                }
            }
        }
        // execute the processes in queue 2
        else if (!q2.empty())
        {
            process p = q2.front();
            q2.pop();
            cout << p.name << " ";
            clock += p.cpu_burst_time;
            p.turnaround_time = clock - p.arrival_time;
            p.waiting_time = p.turnaround_time - p.cpu_burst_time;
            // add any new arrivals to queue 2
            for (int i = 0; i < num_processes; i++)
            {
                if (processes[i].queue_number == 2 && processes[i].arrival_time <= clock)
                {
                    q2.push(processes[i]);
                }
            }
        }
    }
    cout << endl;

    // print the table of information
    cout << "Process\tArrival Time\tBurst Time\tQueue Number\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < num_processes; i++)
    {
        cout << processes[i].name << "\t" << processes[i].arrival_time << "\t" << processes[i].cpu_burst_time;
    }
}