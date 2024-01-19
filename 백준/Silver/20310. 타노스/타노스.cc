#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int zeroCnt = 0;
	int oneCnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0')zeroCnt++;
		else oneCnt++;
	}
	zeroCnt /= 2;
	oneCnt /= 2;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '1')
		{
			s.erase(i, 1); i--;
			oneCnt--;
		}
		if (oneCnt == 0) break;
	}
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == '0')
		{
			s.erase(i, 1);
			zeroCnt--;
		}
		if (zeroCnt == 0)break;
	}
	cout << s << '\n';
	return 0;
}