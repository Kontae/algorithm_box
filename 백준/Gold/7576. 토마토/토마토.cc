#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int arr[1001][1001];
int dist[1001][1001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> m >> n;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			dist[i][j] = -1;
			if (arr[i][j] == 1)
			{
				q.push({ i,j });
				dist[i][j] = 0;
			}
		}
	}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (arr[nx][ny] == 0 && dist[nx][ny] == -1)
			{
				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}

	int answer = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			answer = max(answer, dist[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0 && dist[i][j] == -1) answer = -1;
		}
	}
	cout << answer << '\n';
	return 0;
}