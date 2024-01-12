#include <set>
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	set<string> set;
	int n; char g;
	int tmp = 0;
	cin >> n >> g;
	if (g == 'Y')tmp = 1;
	else if (g == 'F')tmp = 2;
	else tmp = 3;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		set.insert(s);
	}
	cout << set.size() / tmp << '\n';
	return 0;
}