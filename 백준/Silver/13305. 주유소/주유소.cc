#include <iostream>
using namespace std;
#define MX 100001
typedef long long ll;
//dist[1] ==> 1번째 도시부터 2번째 도시까지의 거리
ll dist[MX];
//price[1] ==> 1번째 도시의 리터당 가격
ll price[MX];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll N;
	ll answer = 0;
	cin >> N;
	
	
	for (ll i = 1; i <= N - 1; i++)
	{
		cin >> dist[i];
	}
	for (ll i = 1; i <= N; i++)
	{
		cin >> price[i];
	}
	bool flag = false;
	ll tmp = 0;
	for (ll i = 1; i <= N - 1; i++)
	{
		answer += price[i] * dist[i];
		if (price[i] < price[i + 1])
		{
			price[i + 1] = price[i];
		}
	}
	cout << answer << '\n';
	return 0;
}