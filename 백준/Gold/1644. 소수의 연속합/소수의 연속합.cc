#include <iostream>
#include <vector>
using namespace std;
int prime[4000001];
vector<int> v;
int Num;
void PushPrimeNum()
{
	for (int i = 2; i <= Num; i++)
	{
		prime[i] = i;
	}
	for (int i = 2; i * i <= Num; i++)
	{
		if (prime[i] == 0) continue;
		for (int j = i * 2; j <= Num; j += i)
		{
			prime[j] = 0;
		}
	}
	for (int i = 2; i <= Num; i++)
	{
	
		if (prime[i] != 0) v.push_back(i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> Num;
	if (Num == 1)
	{
		cout << 0 << '\n';
		return 0;
	}
	PushPrimeNum();
	int n = v.size();
	int left = 0;
	int right = 0;
	int sum = v[0];
	int answer = 0;
	while (right < n-1)
	{
		if (sum < Num)
		{
			sum += v[++right];
		}
		else if (sum > Num)
		{
			sum -= v[left++];
		}
		else
		{
			answer++;
			sum += v[++right];
			sum -= v[left++];

		}
	}
	if (prime[Num] != 0)answer++;
	cout << answer << '\n';
	return 0;
}