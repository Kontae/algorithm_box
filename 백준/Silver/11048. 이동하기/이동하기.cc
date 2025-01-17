/*
https://www.acmicpc.net/problem/11048
11048. 이동하기 (S2)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int arr[1001][1001];
	int S[1001][1001];
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int maxCandy = max(max(S[i - 1][j], S[i][j - 1]), S[i - 1][j - 1]);
			S[i][j] = maxCandy + arr[i][j];
		}
	}

	cout << S[n][m] << '\n';

	return 0;
}
