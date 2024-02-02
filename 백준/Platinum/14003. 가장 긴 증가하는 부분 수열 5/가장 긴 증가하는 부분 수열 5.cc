#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int arr[1000001];
int idx[1000001];
vector<int> sorted;
vector<int> answer;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (sorted.size() == 0 || sorted.back() < arr[i])
		{
			sorted.push_back(arr[i]);
			idx[i] = sorted.size() - 1;
			continue;
		}
		int low = 0;
		int high = sorted.size() - 1;
		while (low <= high)
		{
			int mid = (low + high) >> 1;
			if (sorted[mid] >= arr[i]) high = mid - 1;
			else low = mid + 1;
		}
		sorted[low] = arr[i];
		idx[i] = low;
	}
	int tmp = sorted.size() - 1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (tmp == idx[i])
		{
			answer.push_back(arr[i]);
			tmp--;
		}
	}
	reverse(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	for (auto x : answer)
	{
		cout << x << " ";
	}
	return 0;
}