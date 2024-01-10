#include <iostream>
#include <algorithm>
using namespace std;

int DP[1001][4];
int N;

int main(void)
{
	int answer = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> DP[i][j];
		}
	}
	for (int i = 1; i <= N; i++)
	{
		DP[i][1] += min(DP[i - 1][2], DP[i - 1][3]);
		DP[i][2] += min(DP[i - 1][1], DP[i - 1][3]);
		DP[i][3] += min(DP[i - 1][1], DP[i - 1][2]);
	}
	answer = min(min(DP[N][1], DP[N][2]), DP[N][3]);
	cout << answer << '\n';
}