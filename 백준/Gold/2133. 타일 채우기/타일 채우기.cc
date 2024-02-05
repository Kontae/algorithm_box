#include <iostream>
using namespace std;
int N;
int DP[31];

int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; i += 2)
		DP[i] = 0;
	DP[0] = 1;
	DP[2] = 3;

	for (int i = 4; i <= N; i += 2)
	{
		DP[i] = DP[i - 2] * DP[2];
		for (int j = 0; j <= i - 4 ; j += 2)
		{
			DP[i] += DP[j] * 2;
		}
	}

	cout << DP[N] << '\n';
}