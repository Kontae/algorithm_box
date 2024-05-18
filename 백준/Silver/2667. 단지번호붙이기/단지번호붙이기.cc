#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, cnt;
int Map[26][26];
bool Select[26][26];
vector<int> v;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
void Input() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			scanf("%1d", &Map[i][j]);
	}
}
void DFS(int x, int y) {
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx <= N && ny <= N)
		{
			if (Select[nx][ny] == false && Map[nx][ny] == 1)
			{
				Select[nx][ny] = true;
				cnt++;
				DFS(nx, ny);
			}
		}
	}
}
int main(void)
{
	Input();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Select[i][j] == false && Map[i][j] == 1)
			{
				Select[i][j] = true;
				cnt++;
				DFS(i, j);
				v.push_back(cnt);
				cnt = 0;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}
}