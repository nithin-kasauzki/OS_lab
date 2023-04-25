#include <iostream>
#include <algorithm>

using namespace std;

struct Process
{
    int pid;
    int burst;
    int priority;
    int arival;
    int turnAround;
    int waiting;
};

bool cmp(Process a, Process b)
{
    return a.priority > b.priority;
}

int main()
{
    float avgW = 0;
    float avgT = 0;
    Process p[] = {
        {1, 12, 2, 0, 0, 0},
        {2, 25, 1, 0, 0, 0},
        {3, 13, 3, 0, 0, 0},
        {4, 7, 5, 0, 0, 0},
        {5, 11, 4, 0, 0, 0},
    };
    sort(p, p + 5, cmp);
    int t = 0;
    cout << "Gantt chart\n0-";
    for (int i = 0; i < 5; i++)
    {
        cout << "P" << p[i].pid;
        p[i].waiting = t - p[i].arival;
        t += p[i].burst;
        p[i].turnAround = p[i].burst + p[i].waiting;
        cout << "-" << t << "-";
    }
    cout << "\nID \tBt \tPrio\tTurn\tWait";
    for (int i = 0; i < 5; i++)
    {
        avgT += p[i].turnAround;
        avgW += p[i].waiting;
        cout << "\nP" << p[i].pid << "\t" << p[i].burst << "\t" << p[i].priority << "\t" << p[i].turnAround << "\t" << p[i].waiting;
    }

    cout << "\nAvg Turnarounf:" << avgT / 5 << "\nAvg Waiting time:" << avgW / 5 << "\n";
}
