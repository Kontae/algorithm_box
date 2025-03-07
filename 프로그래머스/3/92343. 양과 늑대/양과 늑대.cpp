#include <string>
#include <vector>

using namespace std;
int answer = 0;

// 그래프 연결
void connectGraph(vector<vector<int>>& graph, vector<vector<int>>& edges)
{
    for(auto& x : edges)
    {
        int from = x[0];
        int to = x[1];
        graph[from].push_back(to);
    }
}

// 초기 0번 노드 연결 세팅
void initNext(vector<int>& next, vector<vector<int>>& graph)
{
    for(int i=0;i<graph[0].size();i++)
    {
        next.push_back(graph[0][i]);
    }
}

void dfs(vector<vector<int>>& graph, vector<int>& info, vector<int>& next, int sheep, int wolf, int cur)
{
    if(info[cur]) wolf++;
    else sheep++;
    if(sheep<=wolf) return;
    answer=answer>sheep?answer:sheep;
    
    for(int i=0;i<next.size();i++)
    {
        vector<int> tmp = next;
        tmp.erase(tmp.begin()+i);
        for(int j=0;j<graph[next[i]].size();j++)
        {
            tmp.push_back(graph[next[i]][j]);
        }
        dfs(graph,info,tmp,sheep,wolf,next[i]);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    
    vector<vector<int>> graph(info.size());
    vector<int> next;
    connectGraph(graph,edges);
    initNext(next,graph);
    dfs(graph,info,next,0,0,0);
    
    return answer;
}