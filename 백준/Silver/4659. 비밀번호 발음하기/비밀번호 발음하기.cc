#include <iostream>
#include <string>

using namespace std;
//1 => 자음  0 => 모음
int alp[26] = { 1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0 };
char moeum[5] = { 'a','e','i','o','u' };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while (cin >> s)
	{
		if (s == "end") break;
		//조건 1
		bool cond_1 = false;
		for (int i = 0; i < 5; i++)
		{
			auto it = s.find(moeum[i]);
			if (it != string::npos) cond_1 = true;
		}
		if (cond_1 == false)
		{
			cout << "<" << s << "> is not acceptable.\n";
			continue;
		}
		//조건 2
		int jacnt = 0;
		int mocnt = 0;
		bool cond_2 = true;
		for (int i = 0; i < s.size(); i++)
		{
			if (alp[s[i]-'a'] == 1)
			{
				jacnt = 0;
				mocnt++;
			}
			else
			{
				mocnt = 0;
				jacnt++;
			}
			if (jacnt == 3 || mocnt == 3)
			{
				cond_2 = false;
				break;
			}
		}
		if (!cond_2)
		{
			cout << "<" << s << "> is not acceptable.\n";
			continue;
		}
		//조건 3
		bool cond_3 = true;
		for (int i = 0; i < s.size()-1; i++)
		{
			if (s[i] == s[i + 1])
			{
				if (s[i] != 'e' && s[i] != 'o')
				{
					cond_3 = false;
					break;
				}
			}
		}
		if (!cond_3)
		{
			cout << "<" << s << "> is not acceptable.\n";
			continue;
		}
		cout << "<" << s << "> is acceptable.\n";
	}
	return 0;
}