#include <iostream>
using namespace std;
int arr[1000001];
int n, m, x, y, type;
int GetP(int a)
{
	if (arr[a] == a) return a;
	return arr[a] = GetP(arr[a]);
}

void Union(int a, int b)
{
	a = GetP(a);
	b = GetP(b);
	if (a < b) arr[b] = a;
	else arr[a] = b;
}
void Find(int a, int b)
{
	a = GetP(a);
	b = GetP(b);
	if (a == b) cout << "YES\n";
	else cout << "NO\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
	{
		arr[i] = i;
	}
	while (m--)
	{
		cin >> type >> x >> y;
		if (type == 0) Union(x, y);
		else Find(x, y);
	}
	return 0;
}