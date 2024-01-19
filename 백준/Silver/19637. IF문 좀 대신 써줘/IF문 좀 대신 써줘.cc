#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	vector<pair<string, int>> v(N, { "",0 });
	for (int i = 0; i < N; i++)
	{
		string s;
		long long n;
		cin >> s >> n;
		v[i] = { s,n };
	}
	while (M--)
	{
		int n;
		cin >> n;
		int low = 0;
		int high = N - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (v[mid].second >= n) high = mid - 1;
			else low = mid + 1;
		}
		cout << v[low].first << '\n';
	}

	return 0;
}