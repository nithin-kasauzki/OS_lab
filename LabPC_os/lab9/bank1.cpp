
#include <iostream>
#include <vector>
#include <vector>
using namespace std;

int main()
{

    int n = 5, m = 4;

    int work[] = {3, 4, 0, 1};
    int need[n][m];

    int max_need[][] = {{3, 2, 4, 2},
                        {3, 5, 1, 2},
                        {2, 7, 7, 5},
                        {5, 5, 0, 8},
                        {6, 2, 1, 4}};

    int alloc[][] = {{1, 0, 2, 0},
                     {0, 3, 1, 2},
                     {2, 4, 5, 1},
                     {3, 0, 0, 6},
                     {4, 2, 1, 3}};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max_need[i][j] - alloc[i][j];
        }
    }

    int count = 0;
    bool visited[n] = {false};
    vector<int> order;
    while (count < n)
    {

        bool onexists = false;

        for (int i = 0; i < n; i++)
        {

            if (visited[i] == false)
            {

                bool fail = false;

                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        fail = true;
                        break;
                    }
                }

                if (fail)
                    continue;

                onexists = true;

                order.push_back(i);
                onexists = true;
                count++;
                visited[i] = true;
                for (int k = 0; k < m; k++)
                {
                    work[k] += alloc[i][k];
                }
            }
        }

        if (onexists == false)
        {
            cout << "count=" << count << " ";
            cout << "banking is not safe\n";
            return 0;
        }
    }

    cout << "Its SAfE\norder is : ";
    for (int i = 0; i < order.size(); i++)
    {
        cout << "P" << order[i] << " -> ";
    }

    return 0;
}
