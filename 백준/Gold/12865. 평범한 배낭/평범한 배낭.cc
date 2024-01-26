#include <iostream>
#include <vector>
using namespace std;
int MAX(int a, int b)
{
	return (a > b ? a : b);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, weight, price;
	
	cin >> n >> k;
	vector<pair<int, int>> bag(101);
	vector<vector<int>> DP(n+1, vector<int>(k+1, 0));
	for (int i = 1; i <= n; i++)
	{
		cin >> bag[i].first >> bag[i].second;
	}
	//물건 번호
	for (int i = 1; i <= n; i++)
	{
		//무게
		for (int j = 1; j <= k; j++)
		{
			if (j - bag[i].first >= 0)
			{
				DP[i][j] = MAX(DP[i-1][j], DP[i-1][j - bag[i].first] + bag[i].second);
				
			}
			else
			{
				DP[i][j] = DP[i-1][j];
			}
		}
	}
	/*for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=k;j++)
		{
			cout << DP[i][j] << " ";
		}
		cout << '\n';
	}*/
	cout << DP[n][k] << '\n';
	return 0;
}