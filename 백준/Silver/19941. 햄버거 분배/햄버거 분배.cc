#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	string s;
	cin >> s;
	int answer = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'P')
		{
			for (int j = i - K; j <= i + K; j++)
			{
				if (j < 0 || j >= s.size()) continue;
				if (s[j] == 'H')
				{
					s[j] = 'X';
					s[i] = 'X';
					answer++;
					break;
				}

			}
		}
	}
	cout << answer << '\n';
	return 0;
}