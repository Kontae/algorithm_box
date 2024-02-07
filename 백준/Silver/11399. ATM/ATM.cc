#include <iostream>
#include <queue>
using namespace std;
int n, x, ans, tmp;
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	while (n--)
	{
		cin >> x; pq.push(x);
	}
	while (!pq.empty())
	{
		tmp += pq.top();
		ans += tmp;
		pq.pop();
	}
	cout << ans << '\n';
	return 0;
}