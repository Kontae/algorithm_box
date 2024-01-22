#include <iostream>
using namespace std;
int N;
char plmieq[11][11];
int Select[11];

bool Check(int idx)
{
	int sum = 0;
	for (int i = idx; i >= 0; i--)
	{
		sum += Select[i];
		if (plmieq[i][idx] == '+' && sum <= 0)return false;
		if (plmieq[i][idx] == '-' && sum >= 0)return false;
		if (plmieq[i][idx] == '0' && sum != 0)return false;
	}
	return true;
}
void DFS(int cnt)
{
	if (cnt == N)
	{
		for (int i = 0; i < cnt; i++)
		{
			cout << Select[i] << " ";
		}
			exit(0);
	}
	for (int i = -10; i <= 10; i++)
	{
		Select[cnt] = i;
		if (Check(cnt) == true)DFS(cnt + 1);
	}
}
int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++)
			cin >> plmieq[i][j];
	DFS(0);
}