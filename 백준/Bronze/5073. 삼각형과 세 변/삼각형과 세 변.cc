#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a[3];
	while (cin >> a[0] >> a[1] >> a[2])
	{
		if (a[0]==0 && a[1]==0 && a[2]==0) break;
		sort(a, a + 3);
		if (a[2] >= a[1] + a[0])
		{
			cout << "Invalid\n";
			continue;
		}
		if (a[2] == a[1] && a[1] == a[0])
		{
			cout << "Equilateral\n";
			continue;
		}
		if (a[1] == a[0]||a[2]==a[1])
		{
			cout << "Isosceles\n";
			continue;
		}
		cout << "Scalene\n";
		
		
	}

	return 0;
}