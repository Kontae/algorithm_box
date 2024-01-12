#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;
struct medal {
	int gold;
	int silver;
	int bronze;
};
bool cmp(pair<int, medal> a, pair<int, medal> b)
{
	if (a.second.gold == b.second.gold && a.second.silver == b.second.silver && a.second.bronze == b.second.bronze) return a.first==K;
	if (a.second.gold == b.second.gold && a.second.silver == b.second.silver)return a.second.bronze > b.second.bronze;
	if (a.second.gold == b.second.gold) return a.second.silver > b.second.silver;
	return a.second.gold > b.second.gold;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	vector<pair<int,medal>> country;
	for (int i = 0; i < N; i++)
	{
		int n, g, s, b; 
		medal m;
		cin >> n >> m.gold >> m.silver >> m.bronze;
		country.push_back({ n,m });
	}
	sort(country.begin(), country.end(), cmp);
	for (int i=0;i<country.size();i++)
	{
		if (country[i].first == K)
		{
			cout << i+1 << '\n';
		}
	}
	return 0;
}