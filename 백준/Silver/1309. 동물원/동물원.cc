#include <iostream>
#define mod 9901
using namespace std;

int N;
int DP[100001][2];
//0 0 -> 0
//0 1 -> 1
//1 0 -> 2
int main(void)
{
	cin >> N;
	long long answer = 0;
	DP[1][0] = 1;
	DP[1][1] = 1;
	DP[1][2] = 1;
	for (int i = 2; i <= N; i++)
	{
		DP[i][0] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2]) % mod;
		DP[i][1] = (DP[i - 1][0] + DP[i - 1][2]) % mod;
		DP[i][2] = (DP[i - 1][0] + DP[i - 1][1]) % mod;
	}
	answer = (DP[N][0] + DP[N][1] + DP[N][2]) % mod;
	cout << answer << '\n';
}