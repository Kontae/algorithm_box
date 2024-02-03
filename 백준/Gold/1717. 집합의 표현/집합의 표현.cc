#include <iostream>
#include <vector>
using namespace std;
int n, m, type, x, y;
int getParent(int a,vector<int>&root)
{
	if (root[a] == a) return a;
	return root[a] = getParent(root[a],root);
}
void Union(int a, int b,vector<int>&root)
{
	a = getParent(a,root);
	b = getParent(b,root);
	root[a] = b;
}
void Find(int a, int b,vector<int>&root)
{
	a = getParent(a,root);
	b = getParent(b,root);
	if (a == b)cout << "YES\n";
	else cout << "NO\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<int> root(n + 1);
	for (int i = 0; i <= n; i++)
	{
		root[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> type >> x >> y;
		if (type == 0)
		{
			Union(x, y,root);
		}
		else
		{
			Find(x, y,root);
		}
	}
	return 0;
}