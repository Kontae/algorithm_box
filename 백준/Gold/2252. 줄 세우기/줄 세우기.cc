#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> graph(N + 1);
	vector<int> inDegree(N + 1, 0);
	vector<int> result;

	int a, b;
	// 입력
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		inDegree[b]++;
	}

	// 위상정렬
	queue<int> q;
	for (int i= 1; i <= N; i++)
	{
		if (inDegree[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		result.push_back(cur);

		for (int next : graph[cur])
		{
			inDegree[next]--;
			if (inDegree[next] == 0)
			{
				q.push(next);
			}
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << ' ';
	}
	return 0;
}