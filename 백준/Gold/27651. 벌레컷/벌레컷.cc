#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll arr[1000001];
ll sum[1000001];
ll prefix(ll arr[], ll a, ll b)
{
	if (a > b) return 0ll;
	return arr[b + 1] - arr[a];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	ll answer = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum[i + 1] = sum[i] + arr[i];
	}
	ll left = 1;
	ll right = n - 2;
	for (ll i = 0; i < n - 2; i++)
	{
		ll tmp = sum[i + 1] - sum[0];
		left = max(left, i + 1);
		while (prefix(sum, right + 1, n - 1) <= tmp && right > 0)
		{
			right--;
		}
		while (prefix(sum, i + 1, left) <= prefix(sum, left + 1, n - 1) && left < n)
		{
			left++;
		}
		if (right - left + 1 < 0) continue;
		answer += right - left + 1;
	}
	cout << answer;
	return 0;
}