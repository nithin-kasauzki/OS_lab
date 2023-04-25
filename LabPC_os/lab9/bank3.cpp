
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n = 3, m = 1;

    int work[m] = {13};
    int need[n][m];

    int max_need[n][m] = {{20}, {17}, {19}};

    int alloc[n][m] = {{15}, {14}, {12}};

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
