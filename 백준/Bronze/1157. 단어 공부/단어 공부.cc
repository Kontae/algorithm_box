#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<char, int> a, pair<char, int> b)
{
	return a.second > b.second;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	unordered_map<char, int> m;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
		m[s[i]]++;
	}
	vector<pair<char, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);
	if (v.size() != 1 && v[0].second == v[1].second) {
		cout << "?"; return 0;
	}
	cout << v[0].first;
	return 0;
}