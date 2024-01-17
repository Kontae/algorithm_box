#include <iostream>
using namespace std;
long long sum[250001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N, X, x;
	long long mx = -999;
	int cnt = 1;
	cin >> N >> X;
	for (int i = 1; i <= N; i++)
	{
		cin >> x;
		if (i == 0)sum[i] = x;
		else sum[i] = sum[i - 1] + x;
	}
	for (int i = X; i <= N; i++)
	{
		long long tmp = sum[i] - sum[i - X];
		if (mx < tmp)
		{
			mx = tmp;
			cnt = 1;
		}
		else if (mx == tmp)
		{
			cnt++;
		}
	}
	if (mx == 0) cout << "SAD" << '\n';
	else cout << mx << '\n' << cnt << '\n';
	return 0;
}