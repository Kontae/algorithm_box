#include <iostream>
using namespace std;
typedef long long ll;
ll arr[100001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, s;
	long long sum = 0;
	ll min_len = 1e9;
	ll start = 0;
	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int end = 0; end < n; end++)
	{
		sum += arr[end];
		while (sum >= s)
		{
			min_len = min_len < end - start + 1 ? min_len : end - start + 1;
			sum -= arr[start];
			start++;
		}
	}
	if (min_len == 1e9)cout << 0 << '\n';
	else cout << min_len << '\n';
	return 0;
}