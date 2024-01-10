#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int n, m;
bool broke[10] = { false, };
bool check(int num) {
	string s = to_string(num);
	for (int i = 0; i < s.size(); i++) {
		if (broke[s[i] - 48] == 1)
			return false;				//버튼 사용 불가.
	}
	return true;
}
int main(void)
{
	int temp;
	int minimum = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		broke[temp] = true;
	}
	minimum = abs(n - 100);
	for (int i = 0; i <= 1000000; i++)
	{
		if (check(i))
		{
			int tmp = abs(n - i) + to_string(i).size();
			minimum = min(minimum, tmp);
		}
	}
	cout << minimum << '\n';

}