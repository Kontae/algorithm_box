#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, M;
int arr[8][8];
int dp[8][8][4];
int func(int x, int y, int dir)
{
	if (x >= N && (y >= 0 && y < M)) return 0;
	if (x >= N || y >= M || x < 0 || y < 0) return 1e9;
	int &res = dp[x][y][dir];
	if (res != -1)return res;
	if (dir == 0)
	{
		res = min(func(x + 1, y, 1), func(x + 1, y + 1, 2)) + arr[x][y];
	}
	else if (dir == 1)
	{
		res = min(func(x + 1, y - 1, 0), func(x + 1, y + 1, 2)) + arr[x][y];
	}
	else if (dir == 2)
	{
		res = min(func(x + 1, y - 1, 0), func(x + 1, y, 1)) + arr[x][y];
	}
	else
	{
		res = min(min(func(x + 1, y - 1, 0), func(x + 1, y, 1)), func(x + 1, y + 1, 2)) + arr[x][y];
	}
	return res;


}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	int answer = 1e9;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < M; i++)
	{
		answer = min(answer, func(0, i, 3));
	}
	cout << answer << '\n';

	return 0;
}