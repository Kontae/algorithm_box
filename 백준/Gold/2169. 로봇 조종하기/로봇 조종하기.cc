#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
int dist[1001][1001][3];
int map[1001][1001];
bool visit[1001][1001];
int dx[3] = { 1,0,0 };
int dy[3] = { 0,1,-1 };
int DFS(int curx, int cury,int dir)
{
	if (curx == N-1 && cury == M-1) return map[curx][cury];
	if (dist[curx][cury][dir] != -1e9) return dist[curx][cury][dir];
	visit[curx][cury] = true;
	for (int i = 0; i < 3; i++)
	{
		int nx = curx + dx[i];
		int ny = cury + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny]) continue;
		dist[curx][cury][dir] = max(dist[curx][cury][dir], map[curx][cury] + DFS(nx, ny, i));
	}
	visit[curx][cury] = false;
	return dist[curx][cury][dir];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			fill(dist[i][j], dist[i][j] + 3, -1e9);
		}
	}

	cout << DFS(0, 0, 0) << '\n';
	return 0;
}