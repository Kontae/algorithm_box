#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<string> v = { "SK","CY" };
	string winner = "";
	if (N % 2) winner = v[0];
	else winner = v[1];
	cout << winner << '\n';
	return 0;
}