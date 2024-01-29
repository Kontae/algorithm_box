#include <iostream>
using namespace std;
int arr[10001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	int answer = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int left = 0;
	int right = 0;
	int sum = arr[0];
	while (right < n)
	{
		if (sum < m)
		{
			sum += arr[++right];
		}
		else if (sum > m)
		{
			sum -= arr[left++];
		}
		else
		{
			answer++;
			sum -= arr[left++];
			sum += arr[++right];
		}
	}
	cout << answer << '\n';
	return 0;
}