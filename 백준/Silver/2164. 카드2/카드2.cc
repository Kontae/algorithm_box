#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	deque<int> q;
	//1 2 3 4 5 ... N
	for (int i = 1; i <= N; i++)
	{
		q.push_back(i);
	}
	
	if (N == 1)
	{
		cout << 1 << '\n';
		return 0;
	}
	int cnt = 0;
	while (true)
	{
		q.pop_front();
		if (q.size() == 1) break;
		int tmp = q.front();
		q.pop_front();
		q.push_back(tmp);
	}
	cout << q.front() << '\n';
	return 0;
}