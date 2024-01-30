#include <iostream>
#include <string>
#include <queue>
#define MAX 101
using namespace std;
int N, M;
queue<pair <int, int>> q;
int Map[MAX][MAX];
int Dis[MAX][MAX];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
void Input()
{
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < tmp.length(); j++)
		{
			Map[i][j] = tmp[j] - '0';
			Dis[i][j] = 12345678;
		}
	}

}
void BFS()
{
	q.push({ 0,0 });
	Dis[0][0] = 0;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				if (Map[nx][ny] == 1)
				{
					if (Dis[nx][ny] > Dis[x][y] + 1)
					{
						Dis[nx][ny] = Dis[x][y] + 1;
						q.push({ nx,ny });
					}
				}
				else if (Map[nx][ny] == 0)
				{
					if (Dis[nx][ny] > Dis[x][y])
					{
						Dis[nx][ny] = Dis[x][y];
						q.push({ nx,ny });
					}
				}
			}
		}
	}
}
int main(void)
{
	Input();
	BFS();
	cout << Dis[N - 1][M - 1] << '\n';
}