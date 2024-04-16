#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int map[9][9];
int map2[9][9];
bool visit[9][9] = { false, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int cnt = 3;
int ans = 0;
int N, M;
void BFS()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			map2[i][j] = map[i][j];
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (map2[i][j] == 2)
			{
				queue<pair<int, int>> q;
				q.push({ i,j });
				visit[i][j] = true;

				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (map2[nx][ny] == 0 && visit[nx][ny] == false)
						{
							q.push({ nx,ny });
							visit[nx][ny] = true;
							map2[nx][ny] = 2;
						}
					}
				}
			}
		}
	}
	memset(visit, false, sizeof(visit));
	int res = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (map2[i][j] == 0) res++;
		}
	}
	if (ans < res)
	{
		ans = res;
	}
}

void search()
{
	if (cnt == 0)
	{
		return BFS();
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (map[i][j] == 0)
			{
				cnt--;
				map[i][j] = 1;
				search();
				map[i][j] = 0;
				cnt++;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	memset(map, -1, sizeof(map));
	memset(map2, -1, sizeof(map2));
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
		}
	}
	search();

	cout << ans << '\n';


	return 0;
}