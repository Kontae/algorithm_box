#include <iostream>
#include <queue>
using namespace std;
int arr[1001][1001];
//0 : 부순적 없음   1 : 이미 부쉈음
int dist[1001][1001][2];
int dx[] = { 0,0,1 ,-1 };
int dy[] = { 1,-1,0,0 };
bool flag = false;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = s[j] - '0';
		}
	}

	queue<pair<pair<int, int>,int>> q;
	q.push({ { 0,0 },false });
	dist[0][0][0] = 1;
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int broken = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m )
			{
				if (arr[nx][ny] == 1)
				{
					if (!broken)
					{
						dist[nx][ny][1] = dist[x][y][0] + 1;
						q.push({ { nx,ny }, 1 });
					}
				}
				else
				{
					if (!dist[nx][ny][broken])
					{
						q.push({ {nx,ny},broken });
						dist[nx][ny][broken] = dist[x][y][broken] + 1;
					}
				}
			}
		}
	}
	if (dist[n - 1][m - 1][1]!=0) cout << dist[n - 1][m - 1][1];
	else 
	{
		if (dist[n - 1][m - 1][0]!=0) cout << dist[n - 1][m - 1][0];
		else cout << -1 << '\n';
	}
	return 0;
}