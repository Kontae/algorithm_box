#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
struct KCTC {
	int total = 0;
	int cnt = 0;
	int last = 0;
	int id=0;
};

bool cmp(KCTC a, KCTC b)
{
	if (a.total == b.total && a.cnt == b.cnt) return a.last < b.last;
	if (a.total == b.total) return a.cnt < b.cnt;
	return a.total > b.total;
}
//i번 팀의 j문제 제출 점수
int score[101][101] = { 0, };
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc;
	cin >> tc;
	
	while (tc--)
	{
		int n, k, t, m;
		cin >> n >> k >> t >> m;
		vector<KCTC> arr(n, { 0 });
		for (int q = 0; q < m; q++)
		{
			int i, j, s;
			cin >> i >> j >> s;
			score[i][j] = max(s, score[i][j]);
			arr[i-1].cnt += 1;
			arr[i-1].last = q;
			arr[i-1].id = i;
		}
		for (int q = 0; q < n; q++)
		{
			for (int w = 1; w <= k; w++)
			{
				arr[q].total += score[q+1][w];
			}
		}
		sort(arr.begin(),arr.end(), cmp);
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i].id == t)
			{
				cout << i + 1 << '\n';
				break;
			}
		}
		memset(score, 0, sizeof(score));
	}
	return 0;
}