#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<ll> v;
	ll N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	ll low = 0;
	ll high = *max_element(v.begin(), v.end());
	ll answer = 0;
	while (low <= high)
	{
		ll cnt = 0;
		ll mid = (low + high) / 2;
		for (auto x : v)
		{
			if (x >= mid) cnt += x - mid;
		}
		if (cnt >= M)
		{
			low = mid + 1;
			answer = mid;
		}
		else
		{
			high = mid - 1;
		}
	}
	cout << answer << '\n';

	return 0;
}