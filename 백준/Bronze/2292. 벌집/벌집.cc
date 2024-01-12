#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long answer = 0;
	long long n;
	cin >> n;
	long long cnt = 1;
	while (n > 0)
	{
		n -= cnt;
		if (cnt == 1) cnt = 6;
		else cnt += 6;
		answer++;
	}
	cout << answer << '\n';
	return 0;
}