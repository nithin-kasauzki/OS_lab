#include <iostream>
#include <algorithm>
using namespace std;

struct p
{
    int id, bt, at, wt, tat;
};

bool cmp(p a, p b)
{
    return a.at < b.at;
}
int main()
{
    int t_tat = 0, t_wt = 0;
    struct p pr[5] = {{1, 12, 0, 0, 0},
                      {2, 25, 2, 0, 0},
                      {3, 13, 1, 0, 0},
                      {4, 7, 0, 0, 0},
                      {5, 11, 5, 0, 0}};
    sort(pr, pr + 5, cmp);
    int time = 0;
    cout << "-0-";
    for (int i = 0; i < 5; i++)
    {
        cout << " p" << pr[i].id;
        pr[i].wt = time - pr[i].wt;
        pr[i].tat = pr[i].wt + pr[i].bt;
        time += pr[i].bt;
        t_tat += pr[i].tat;
        t_wt += pr[i].wt;
        cout << " -" << time << "-";
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "p" << pr[i].id << " " << pr[i].wt << " " << pr[i].tat << endl;
    }
    cout << "\n"
         << t_tat / 5 << endl;
    cout << t_wt / 5;
}