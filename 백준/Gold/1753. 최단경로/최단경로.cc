#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int v, e, start;
struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.second > b.second;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> v >> e >> start;
	vector<pair<int, int>> graph[20001];
	int dist[20001] = {};
	for (int i = 0; i < e; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		graph[x].push_back({ y,w });
	}
	for (int i = 1; i <= v; i++)
	{
		dist[i] = 1e7;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push({ start,0 });
	dist[start] = 0;
	while (!pq.empty())
	{
		int cur = pq.top().first;
		int cost = pq.top().second;
		pq.pop();
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int ncost = graph[cur][i].second;
			if (dist[next] > cost + ncost)
			{
				dist[next] = cost + ncost;
				pq.push({ next,dist[next] });
			}
		}
	}
	for (int i = 1; i <= v; i++)
	{
		if (dist[i] == 1e7) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
	return 0;

}