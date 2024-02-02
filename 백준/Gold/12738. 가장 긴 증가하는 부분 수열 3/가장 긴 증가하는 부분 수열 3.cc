#include <iostream>
#include <vector>
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
	}
	cout << sorted.size() << '\n';
	return 0;
}