#include <iostream>
using namespace std;
char c[1001][1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	bool flag = false;
	int heart_n = 0, heart_m = 0;
	//허리 밑 마지막 좌표
	int waist_n = 0, waist_m = 0;
	int body[5] = { 0, };
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> c[i][j];
			if (c[i][j] == '*' && !flag)
			{
				heart_n = i + 1;
				heart_m = j;
				flag = true;
			}
		}
	}
	for (int i = heart_m - 1; i >= 0; i--)
	{
		if (c[heart_n][i] == '*') cnt++;
		else break;
	}
	body[0] = cnt; cnt = 0;
	for (int i = heart_m + 1; i < n; i++)
	{
		if (c[heart_n][i] == '*')cnt++;
		else break;
	}
	body[1] = cnt; cnt = 0;

	for (int i = heart_n + 1; i < n; i++)
	{
		if (c[i][heart_m] == '*')
		{
			cnt++;
			waist_n = i;
			waist_m = heart_m;
		}
		else break;
	}
	body[2] = cnt; cnt = 0;
	
	for (int i = waist_n + 1; i < n; i++)
	{
		if (c[i][waist_m - 1] == '*') cnt++;
		else break;
	}
	body[3] = cnt; cnt = 0;
	
	for (int i = waist_n + 1; i < n; i++)
	{
		if (c[i][waist_m + 1] == '*') cnt++;
		else break;
	}
	body[4] = cnt; cnt = 0;

	cout << heart_n + 1 << " " << heart_m + 1 << '\n';
	for (int i = 0; i < 5; i++)
	{
		cout << body[i] << " ";
	}

	return 0;
}