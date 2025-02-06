#include <iostream>

using namespace std;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, cnt = 1, answer = 0;
	cin >> n;
	while (n >= cnt) {
		n -= cnt;
		cnt++;
		answer++;
	}
	cout << answer << '\n';
	return 0;
}