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
	int n, k;
	
	cin >> n >> k;
	vector<pair<int, int>> bag(101);
	vector<int> DP(k + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> bag[i].first >> bag[i].second;
	}
	//물건 번호
	for (int i = 1; i <= n; i++)
	{
		//무게
		for (int j = k; j >= bag[i].first; j--)
		{
			DP[j] = MAX(DP[j], DP[j - bag[i].first] + bag[i].second);
		}
	}
	cout << DP[k] << '\n';
	return 0;
}