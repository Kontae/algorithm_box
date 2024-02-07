#include <iostream>
#include <queue>
using namespace std;
int n, x, ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pqA;
	priority_queue<int> pqB;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		pqA.push(x);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		pqB.push(x);
	}
	while (!pqA.empty())
	{
		ans += (pqA.top() * pqB.top());
		pqA.pop(); pqB.pop();
	}
	cout << ans << '\n';
	return 0;
}