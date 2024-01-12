#include <iostream>
typedef long long ll;
using namespace std;
ll score[51];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll N, new_score, P;
	int idx = -1;
	int cnt = 0;
	cin >> N >> new_score >> P;
	if (N == 0)
	{
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> score[i];
		if (score[i] == new_score) cnt++;
		if (score[i] < new_score && idx == -1)
		{
			idx = i;
		}
	}
	if (idx == -1)
	{
		if (N == P) {
			cout << -1;
			return 0;
		}
		if (N < P) {
			if (score[N] != new_score)
			{
				cout << N + 1;
				return 0;
			}
			else
			{
				cout << N-cnt+1 << '\n';
				return 0;
			}
		}
	}
	else
	{
		cout << idx-cnt << '\n';
		return 0;
	}
}