#include <iostream>
using namespace std;
int price[11];
int n, k, ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> price[i];
	}
	int tmp = n - 1;
	while (k > 0)
	{
		for (int i= tmp; i >= 0; i--)
		{
			if (price[i] <= k)
			{
				ans += k / price[i];
				k %= price[i];
				tmp = i - 1;
				break;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}