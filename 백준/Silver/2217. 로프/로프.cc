#include <iostream>
#include <queue>
using namespace std;
int n, x, cnt, ans = -1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		pq.push(x);
	}
	while (!pq.empty())
	{
		cnt++;
		int num = pq.top();
		if (ans <= num * cnt) ans = num * cnt;
		pq.pop();
	}
	cout << ans << '\n';
	return 0;
}