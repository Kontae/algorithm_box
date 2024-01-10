#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int H, W;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> H >> W;
	vector<vector<char>> arr(H, vector<char> (W));
	vector<vector<bool>> visit(H, vector<bool>(W, false));
	vector<vector<int>> dist(H, vector<int>(W, 1e8));
	for (int i = 0; i < H; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < W; j++)
		{
			arr[i][j] = s[j];
		}
	}
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visit[0][0] = true;
	dist[0][0] = 0;
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nxt_x = cur_x + dx[i];
			int nxt_y = cur_y + dy[i];
			if (nxt_x >= 0 && nxt_y >= 0 && nxt_x < H && nxt_y < W && !visit[nxt_x][nxt_y])
			{
				if (arr[cur_x][cur_y] != arr[nxt_x][nxt_y])
				{
					visit[nxt_x][nxt_y] = true;
					q.push({ nxt_x,nxt_y });
					dist[nxt_x][nxt_y] = min(dist[nxt_x][nxt_y], dist[cur_x][cur_y] + 1);
				}
			}
		}
	}
	if (dist[H - 1][W - 1]==1e8) cout << -1 << '\n';
	else cout << dist[H - 1][W - 1] << '\n';
	return 0;
}