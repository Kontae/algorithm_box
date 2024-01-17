#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int cnt = 0;
	int idx = 0;
	while (cnt++ >= 0)
	{
		string str = to_string(cnt);
		for (int i = 0; i < str.size(); i++)
		{
			if (s[idx] == str[i]) idx++;
			if (idx == s.size())
			{
				cout << cnt << '\n';
				return 0;
			}
		}
	}
	return 0;
}