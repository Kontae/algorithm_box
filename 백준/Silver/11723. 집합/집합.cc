#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	list<int> li;
	list<int> all;
	for (int i = 1; i <= 20; i++)
	{
		all.push_back(i);
	}
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		int n;
		cin >> s;
		if (s == "all")
		{
			li = all;
		}
		else if (s == "empty")
		{
			li.clear();
		}
		else if (s == "add")
		{
			cin >> n;
			auto it = find(li.begin(), li.end(), n);
			if (it == li.end())
			{
				li.push_back(n);
			}
		}
		else if (s == "remove")
		{
			cin >> n;
			auto it = find(li.begin(), li.end(), n);
			if (it != li.end())
			{
				li.erase(it);
			}
		}
		else if (s == "check")
		{
			cin >> n;
			auto it = find(li.begin(), li.end(), n);
			if (it != li.end()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (s == "toggle")
		{
			cin >> n;
			auto it = find(li.begin(), li.end(), n);
			if (it != li.end())li.erase(it);
			else li.push_back(n);
		}
	}
	return 0;
}