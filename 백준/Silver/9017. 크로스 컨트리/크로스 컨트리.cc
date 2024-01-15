#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define mx 9999999
using namespace std;
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
	if (a.first.second == b.first.second) return a.second < b.second;
	return a.first.second < b.first.second;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		vector<int> input(n);
		vector<int> cnt(201);
		for (int i = 0; i < n; i++)
		{
			cin >> input[i];
			cnt[input[i]]++;
		}
		for (int i = 0; i < input.size(); i++)
		{
			if (cnt[input[i]] < 6)
			{
				input.erase(input.begin() + i); i--;
			}
		}
		
		//{팀 번호, 해당 번호가 몇 번 나왔는지}
		vector<pair<int, int>> v(201, { 0, 0});
		//{{팀 번호, 앞에서부터 4번까지의 합}, 5번 째 점수}
		vector<pair<pair<int, int>, int>> score(201, { {0,mx},0 });
		for (int i = 0; i < input.size(); i++)
		{
			int x = input[i];
			if (v[x].second == 0) score[x].first.second = 0;
			v[x].first = x;
			v[x].second++;
			
			//x팀의 4번째까지 점수 더해줌
			if (v[x].second <= 4)
			{
				score[x].first.first = x;
				score[x].first.second += i + 1;
			}
			//x팀의 5번 째 들어오는 사람의 점수
			if (v[x].second == 5)
			{
				score[x].second = i + 1;
			}
		}
		sort(score.begin(), score.end(), cmp);
		cout << score.front().first.first << '\n';
	}

	return 0;
}