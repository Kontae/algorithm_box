
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <sstream>
using namespace std;
vector<string> split(string str, char c)
{
	istringstream iss(str);
	string buffer;
	vector<string> result;
	while (getline(iss, buffer, c))
	{
		result.push_back(buffer);
	}
	return result;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	unordered_set<string> set;
	while (N--)
	{
		string s;
		cin >> s;
		set.insert(s);
	}
	while (M--)
	{
		string s;
		cin >> s;
		vector<string> v = split(s, ',');
		for (int i = 0; i < v.size(); i++)
		{
			if (set.find(v[i]) != set.end())
			{
				auto it = set.find(v[i]);
				set.erase(it);
			}
		}
		cout << set.size() << '\n';
	}
	return 0;
}