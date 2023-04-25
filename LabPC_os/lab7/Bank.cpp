#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m;
    cout << "enter no. of processes:";
    cin >> n;
    cout << "enter no. of types of resources:";
    cin >> m;

    int work[m];
    cout << "enter availability of each resource:";
    for (int i = 0; i < m; i++)
    {
        cin >> work[i];
    }

    int big[n][m];
    for (int i = 0; i < n; i++)
    {
        cout << "max units for P" << i << ": ";
        for (int j = 0; j < m; j++)
        {
            cin >> big[i][j];
        }
    }

    int alloc[n][m];
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << "allocate resources for P" << i << ":";
        for (int j = 0; j < m; j++)
        {
            cin >> alloc[i][j];
        }
    }

    int count = 0;
    bool visited[n] = {false};
    vector<int> order;
    while (count < n)
    {

        bool onexists = false;

        // cout<<"count="<<count<<"\n";
        // cout<<"work="<<work[0]<<","<<work[1]<<","<<work[2]<<","<<"::";
        for (int i = 0; i < n; i++)
        {

            if (visited[i] == false)
            {

                bool fail = false;

                for (int j = 0; j < m; j++)
                {
                    if (alloc[i][j] + work[j] < big[i][j])
                    {
                        fail = true;
                        break;
                    }
                }
                // cout<<"i="<<i<<" fail="<<fail<<"\n";

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

    cout << "order is : ";
    for (int i = 0; i < order.size(); i++)
    {
        cout << "P" << order[i] << " -> ";
    }
    // alloc,max,avail
    return 0;
}
