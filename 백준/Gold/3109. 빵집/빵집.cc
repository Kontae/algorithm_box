#include <iostream>
using namespace std;
bool visit[10001][501];
int R, C;
int ans;
int dx[3] = { -1,0,1 };
int dy[3] = { 1,1,1 };
bool DFS(int x, int y)
{
	if (y == C - 1)
	{
		ans++;
		return true;
	}
	visit[x][y] = true;
	for (int i = 0; i < 3; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C || visit[nx][ny] == true) continue;
		if (DFS(nx, ny)) return true;
	}
	return false;
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < C; j++)
		{
			if (s[j] == '.') visit[i][j] = false;
			else if (s[j] == 'x') visit[i][j] = true;
		}
	}

	for (int i = 0; i < R; i++)
	{
		DFS(i,0);
	}
	cout << ans << '\n';
	return 0;
}