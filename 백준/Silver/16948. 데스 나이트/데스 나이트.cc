#include <iostream>
#include <queue>
using namespace std;
int dx[6] = { -2,-2,0,0,2,2 };
int dy[6] = { -1,1,-2,2,-1,1 };
int arr[201][201];
bool visit[201][201];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    queue<pair<int, pair<int, int>>> q;
    int N, r1, r2, c1, c2;
    cin >> N >> r1 >> c1 >> r2 >> c2;
    q.push({ 0,{r1,c1} });
    visit[r1][c1] = true;
    while (!q.empty())
    {
        int cnt = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        if (x == r2 && y == c2)
        {
            cout << cnt << '\n';
            break;
        }
        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N && visit[nx][ny] == false)
            {
                visit[nx][ny] = true;
                q.push({ cnt + 1,{nx,ny} });
            }
        }
    }
    if (!visit[r2][c2]) cout << -1 << '\n';

    return 0;
}
