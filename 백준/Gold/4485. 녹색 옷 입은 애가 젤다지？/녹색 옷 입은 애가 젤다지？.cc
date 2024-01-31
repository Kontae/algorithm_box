#include <iostream>
#include <queue>
using namespace std;
int arr[126][126];
int cost[126][126];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
struct Point {
	int x, y;
};

struct cmp {
	bool operator()(pair<Point,int> a, pair<Point, int> b)
	{
		return a.second > b.second;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int tc = 0;
	priority_queue<pair<Point, int>,vector<pair<Point,int>>, cmp> q;
	while (cin >> n)
	{
		if (n == 0) break;
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				cost[i][j] = 1e7;
			}
		}
		cost[0][0] = arr[0][0];
		q.push({ {0,0},cost[0][0] });
		while (!q.empty())
		{
			int x = q.top().first.x;
			int y = q.top().first.y;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
				if (cost[nx][ny] > cost[x][y] + arr[nx][ny])
				{
					cost[nx][ny] = cost[x][y] + arr[nx][ny];
					q.push({ {nx,ny},cost[x][y] + arr[nx][ny] });
				}
			}
		}

		cout << "Problem " << ++tc << ": " << cost[n-1][n-1] << '\n';
	}
	return 0;
}