#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
char arr[1001][1001];
int distJ[1001][1001];
int distF[1001][1001];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
int ji_x, ji_y, fire_x, fire_y;
int answer = 1e9;
queue<pair<int, int>> q;
void Input()
{
	cin >> n >> m;
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = s[j];
			if (s[j] == 'J')
			{
				ji_x = i; ji_y = j;
			}
			else if (s[j] == 'F')
			{
				fire_x = i; fire_y = j;
				q.push({ fire_x,fire_y });
				distF[fire_x][fire_y] = 1;
			}
		}
	}
}
//Fire의 위치를 동시에 모두 넣어줘야함!!!

void initF()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && arr[nx][ny] != '#' && !distF[nx][ny])
			{
				
				q.push({ nx,ny });
				distF[nx][ny] = distF[x][y] + 1;
			}
		}
	}
}
void initJ()
{
	//{{좌표}, cnt}
	q.push({ ji_x,ji_y });
	distJ[ji_x][ji_y] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int tmp = distJ[x][y] + 1;
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && arr[nx][ny] != '#' && !distJ[nx][ny]&&(distF[nx][ny]>tmp||distF[nx][ny]==0))
			{
				q.push({ nx,ny });
				distJ[nx][ny] = tmp;
			}
		}
	}

}
int Check()
{
	for (int i = 0; i < n; i++)
	{

		if (distJ[i][0])
		{
			answer = answer < distJ[i][0] ? answer : distJ[i][0];
		}
		if (distJ[i][m-1])
		{
			answer = answer < distJ[i][m - 1] ? answer : distJ[i][m - 1];
		}
	}
	for (int j = 0; j < m; j++)
	{
		if (distJ[0][j])
		{
			answer = answer < distJ[0][j] ? answer : distJ[0][j];
		}
		if (distJ[n-1][j])
		{
			answer = answer < distJ[n - 1][j] ? answer : distJ[n - 1][j];
		}
	}
	return answer;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	Input();
	initF();
	initJ();
	if (Check() == 1e9)cout << "IMPOSSIBLE" << '\n';
	else cout << Check() << '\n';
	
	return 0;
}