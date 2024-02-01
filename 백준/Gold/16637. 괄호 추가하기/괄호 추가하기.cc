#include <iostream>
#include <climits>
using namespace std;
int n;
string s;
int answer = INT_MIN;
int cal(int a, int b, char oper)
{
	if (oper == '+') return a + b;
	if (oper == '-')return a - b;
	if (oper == '*')return a * b;
}
void DFS(int idx, int num)
{
	if (idx > n - 1)
	{
		answer = answer > num ? answer : num;
		return;
	}
	char op;
	if (idx == 0) op = '+';
	else op = s[idx - 1];
	
	if (idx + 2 < n)
	{
		int tmp = cal(s[idx] - '0', s[idx + 2] - '0', s[idx + 1]);
		DFS(idx + 4, cal(num, tmp, op));
	}
	DFS(idx + 2, cal(num, s[idx] - '0', op));
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