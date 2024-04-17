#include <iostream>
#include <queue>
using namespace std;
bool visit[1501][1501];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	int sum = a + b + c;
	if (sum % 3)
	{
		cout << 0 << '\n';
		return 0;
	}
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		int stone[3] = { x,y,sum - x - y };
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (stone[i] < stone[j])
				{
					int nx = stone[i] * 2;
					int ny = stone[j] - stone[i];
					if (visit[nx][ny] == false)
					{
						visit[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		q.pop();

	}
	if (visit[sum / 3][sum / 3] == true) cout << 1 << '\n';

	else cout << 0 << '\n';
	return 0;
}