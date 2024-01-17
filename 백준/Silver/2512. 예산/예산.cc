#include <iostream>
using namespace std;
int arr[10001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	int mx = -99;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (mx < arr[i]) mx = arr[i];
	}
	cin >> M;
	long long low = 0;
	long long high = mx;
	while (low <= high)
	{
		long long mid = (low + high) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++)
		{
			if (arr[i] <= mid)
			{
				sum += arr[i];
			}
			else sum += mid;
		}
		if (sum > M)
		{
			high = mid - 1;
		}
		else low = mid + 1;
	}
	cout << high << '\n';
	return 0;
}