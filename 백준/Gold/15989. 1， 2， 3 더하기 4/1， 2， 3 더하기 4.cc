#include <iostream>
using namespace std;
int dp[10002][4];
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc;
	cin >> tc;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = 1;
		}
	}
	for (int i = 4; i <= 10001; i++)
	{
		dp[i][1] = 1;
		dp[i][2] = 1 + dp[i - 2][2];
		dp[i][3] = 1 + dp[i - 3][2] + dp[i - 3][3];
	}
	while (tc--)
	{
		int n;
		cin >> n;
		cout << 1 + dp[n][2] + dp[n][3] << '\n';
	}
	return 0;
}