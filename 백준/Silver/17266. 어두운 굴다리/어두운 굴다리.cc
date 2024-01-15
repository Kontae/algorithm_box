#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M, x;
	cin >> N >> M;
	vector<int> v(100001);
	for (int i = 0; i < M; i++)
	{
		cin >> v[i];
	}
	int left = 0;
	int right = 100000;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		//0 ~ 처음값
		if (v[0] > mid)
		{
			left = mid + 1;
			continue;
		}
		//끝값 ~ M
		if (N - v[M - 1] > mid)
		{
			//mid가 더 커야함
			left = mid + 1;
			continue;
		}
		bool flag = 0;
		for (int i = 1; i < M; i++)
		{
			if (v[i] - v[i - 1] > 2 * mid)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			left = mid + 1;
			continue;
		}
		right = mid - 1;
	}
	cout << left << '\n';
	return 0;
}