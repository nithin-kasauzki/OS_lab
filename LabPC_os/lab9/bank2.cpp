
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n = 5, m = 4;

    int work[m] = {1, 5, 2, 0};
    int need[n][m];

    int max_need[n][m] = {{0, 0, 1, 2},
                          {1, 7, 5, 0},
                          {2, 6, 5, 6},
                          {0, 6, 5, 2},
                          {0, 6, 5, 6}};

    int alloc[n][m] = {{0, 0, 1, 2},
                       {1, 0, 0, 0},
                       {1, 3, 5, 4},
                       {0, 6, 3, 2},
                       {0, 0, 1, 4}};

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
                // cout<<"pushing p"<<i<<"\n";
                order.push_back(i);
                onexists = true;
                count++;
                visited[i] = true;
                for (int k = 0; k < m; k++)
                { // adding resources back to work
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
