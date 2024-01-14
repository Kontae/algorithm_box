#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> graph[300001];
vector<int> dis;
vector<int> answer;
int N, M, K, X;

void BFS()
{
	queue<int> q;
	q.push(X);
	dis[X] = 0;
	
	int cnt = 0;
	while (!q.empty())
	{
		int n = q.front();
		q.pop();
		for (int i = 0; i < graph[n].size(); i++)
		{
			int next = graph[n][i];
			if (dis[next]==-1)
			{
				dis[next] = dis[n] + 1;
				q.push(next);
			}

		}

	}
	for (int i = 0; i < N; i++)
	{
		if (K == dis[i + 1])
			answer.push_back(i+1);
	}

}
int main()
{
	cin >> N >> M >> K >> X;
	dis = vector<int>(300001, -1);
	for (int i = 0; i < M; i++)
	{
		int a;
		int b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	BFS();
	if (answer.empty())
	{
		cout << -1;
		return 0;
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)	cout << answer[i] << '\n';
	return 0;
}