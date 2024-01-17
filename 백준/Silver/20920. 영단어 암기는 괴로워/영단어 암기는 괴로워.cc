#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<string, int>& a, pair<string, int>& b)
{
	if (a.second == b.second && a.first.size() == b.first.size())
	{
		return a.first < b.first;
	}
	if (a.second == b.second)
	{
		return a.first.size() > b.first.size();
	}
	return a.second > b.second;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	unordered_map<string, int> m;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		if (s.size() >= M)
		{
			m[s]++;
		}
	}
	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);
	for (auto x : v)
	{
		cout << x.first << '\n';
	}
	return 0;
}