#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<pair<int, int>>v(20);
	while (N--)
	{
		int tc;
		int answer = 0;
		cin >> tc;
		for (int i = 0; i < 20; i++)
		{
			int n;
			cin >> n;
			v[i] = { n,i };
		}
		for (int i = 0; i < 20; i++)
		{
			for (int j = i; j < 20; j++)
			{
				if (v[i] > v[j]) answer++;
			}
		}
		cout << tc << " " << answer << '\n';
		v.clear();
		v.resize(20);
	}

	return 0;
}