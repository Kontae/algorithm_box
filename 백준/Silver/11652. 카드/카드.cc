#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long ll;
ll arr[100001];
bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	unordered_map<ll, ll> map;
	vector<pair<ll, ll>> v;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		map[arr[i]]++;
	}
	for (auto it = map.begin(); it != map.end(); it++) {
		v.push_back({ it->first,it->second });
	}
	sort(v.begin(), v.end(), cmp);

	cout << v[0].first << '\n';
	return 0;
}