#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> word_cnt;

vector<int> Count(string s)
{
	vector<int> alp(26, 0);
	for (int i = 0; i < s.size(); i++)
	{
		alp[s[i]-'A']++;
	}
	return alp;
}
bool Check(string s)
{
	vector<int> str_cnt = Count(s);
	vector<int> dif;
	for (int i = 0; i < 26; i++)
	{
		if (word_cnt[i] != str_cnt[i])
		{
			dif.push_back(word_cnt[i] - str_cnt[i]);
		}
	}
	if (dif.empty()) return true;
	if (dif.size() == 1 && abs(dif.front()) == 1)return true;
	if (dif.size() == 2 && abs(dif.front()) == 1 && dif.front() + dif[1] == 0)return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string word;
	cin >> n;
	cin >> word;
	word_cnt = Count(word);
	int answer = 0;
	for (int i = 0; i < n-1; i++)
	{
		string s;
		cin >> s;
		if (Check(s)) answer++;
	}
	cout << answer << '\n';
	return 0;
}