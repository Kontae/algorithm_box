#include <iostream>
#include <cmath>
using namespace std;
int n;
int answer = (-1) * pow(2, 31);
string s;
int MAX(int a, int b)
{
	return (a > b ? a : b);
}
int cal(int a, int b, char oper)
{
	if (oper == '+') return a + b;
	else if (oper == '-')return a - b;
	else if (oper == '*')return a * b;
	return 0;
}
void DFS(int cnt, int num)
{
	if (cnt > n - 1)
	{
		answer = MAX(answer, num);
		return;
	}
	char op;
	if (cnt == 0)
	{
		op = '+';
	}
	else
	{
		op = s[cnt - 1];
	}
	if (cnt + 2 < n)
	{
		int tmp = cal(s[cnt] - '0', s[cnt + 2] - '0', s[cnt + 1]);
		DFS(cnt + 4, cal(num, tmp, op));
	}
	DFS(cnt + 2, cal(num, s[cnt] - '0', op));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	DFS(0, 0);
	cout << answer << '\n';
	return 0;
}