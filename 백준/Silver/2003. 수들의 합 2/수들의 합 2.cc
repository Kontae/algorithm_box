#include <iostream>
using namespace std;
int sum[10001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	int answer = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}
	for (int left = 0; left < n; left++)
	{
		int right = left + 1;
		while (right <= n)
		{
			int tmp = sum[right] - sum[left];
			if (tmp == m)
			{
				answer++;
				break;
			}
			else if (tmp > m)
			{
				break;
			}
			right++;
		}
	}
	cout << answer << '\n';
	return 0;
}