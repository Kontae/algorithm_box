#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, ans = 1;
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), cmp);
	int end = v.front().second;
	for (int i = 1; i < n; i++)
	{
		if (v[i].first >= end)
		{
			ans++;
			end = v[i].second;
		}
	}
	cout << ans << '\n';
	return 0;
}