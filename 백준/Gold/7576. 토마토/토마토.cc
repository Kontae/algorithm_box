#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int M, N;
int Map[1001][1001];
int Check[1001][1001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
queue<pair<int, int>> q;
int main(void) 
{
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
			Check[i][j] = -1;
			if (Map[i][j] == 1)
			{
				q.push({ i,j });
				Check[i][j] = 0;
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
			if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			{
				if (Map[nx][ny] == 0 && Check[nx][ny] == -1)
				{
					Check[nx][ny] = Check[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
	int answer = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			answer = max(answer, Check[i][j]);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Check[i][j] == -1 && Map[i][j] == 0)
				answer = -1;
		}
	}
	cout << answer << '\n';
}