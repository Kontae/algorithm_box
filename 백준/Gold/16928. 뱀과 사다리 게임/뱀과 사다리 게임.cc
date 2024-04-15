#include <iostream>
#include <queue>
using namespace std;
int arr[101];
int dist[101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    queue<int> q;
    int n, m, from, to;
    for (int i = 1; i <= 100; i++)
    {
        arr[i] = i;
        dist[i] = -1;
    }
    cin >> n >> m;
    for (int i = 0; i < n + m; i++)
    {
        cin >> from >> to;
        arr[from] = to;
    }
    dist[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++)
        {
            int y = x + i;
            if (y > 100) continue;
            y = arr[y];
            if (dist[y] == -1) 
            {
                dist[y] = dist[x] + 1;
                q.push(y);
            }
        }
    }
    cout << dist[100] << '\n';
    return 0;
}
