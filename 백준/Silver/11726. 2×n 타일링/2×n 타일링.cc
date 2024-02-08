#include <iostream>
using namespace std;
int N;
int main(void)
{
	long long Arr[1001] = {};
	cin >> N;
	Arr[1] = 1;
	Arr[2] = 2;
	for (int i = 3; i <= N; i++)
	{
		Arr[i] = (Arr[i - 1] + Arr[i - 2]) % 10007;
	}
	cout << Arr[N];
}