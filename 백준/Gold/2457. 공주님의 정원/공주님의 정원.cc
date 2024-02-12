#include <iostream>
#include <algorithm>
using namespace std;
int n, sm, sd, em, ed, ans;
int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
pair<int, int> arr[100001];
int ToDay(int m, int d)
{
	int sum = 0;
	for (int i = 0; i < m - 1; i++)
	{
		sum += month[i];
	}
	return sum + d;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> sm >> sd >> em >> ed;
		arr[i] = { ToDay(sm,sd),ToDay(em,ed) };
	}

	sort(arr, arr + n);
	
	if (arr[0].first > ToDay(3, 1))
	{
		cout << 0 << '\n';
		return 0;
	}
	int s = ToDay(3, 1);
	int e = ToDay(11, 30);
	int mx = -1;
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		int start = arr[i].first;
		int end = arr[i].second;
		if (start <= s)
		{
			mx = mx > end ? mx : end;
			if (mx > e)
			{
				flag = true;
				ans++;
				break;
			}
		}
		else
		{
			if (mx == -1) break;
			ans++;
			s = mx;
			mx = -1;
			i--;
		}
	}
	if (flag == false) cout << 0 << '\n';
	else cout << ans << '\n';
	return 0;
}