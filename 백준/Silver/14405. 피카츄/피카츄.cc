#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	bool flag = true;
	for (int i = 0; i < s.size(); i++)
	{
		
		if (s[i] == 'p' && i != s.size() - 1)
		{
			if (s[i + 1] == 'i')
			{
				i++;
			}
			else
			{
				flag = false;
			}
		}
		else if (s[i] == 'k' && i != s.size() - 1)
		{
			if (s[i + 1] == 'a') i++;
			else flag = false;
		}
		else if (s[i] == 'c' && i != s.size() - 1 && i != s.size() - 2)
		{
			if (s[i + 1] == 'h')
			{
				if (s[i + 2] == 'u')
				{
					i += 2;
				}
				else flag = false;
			}
			else flag = false;
		}
		else flag = false;

		if (flag == false)
		{
			cout << "NO";
			break;
		}
	}

	if (flag == true)
	{
		cout << "YES";
	}
	return 0;
}