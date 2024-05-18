#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

bool cmp(pair<long long, int>& a, pair<long long, int>& b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second > b.second;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	map<long long, int> m;
	vector<pair<long long, int>> v;
	int t;
	cin >> t;
	while (t--)
	{
		long long l;
		cin >> l;
		m[l]++;
	}
	for (auto it = m.begin(); it != m.end(); it++)
	{
		v.push_back({ it->first, it->second });
	}
	sort(v.begin(), v.end(), cmp);
	cout << v[0].first << '\n';
	return 0;
}