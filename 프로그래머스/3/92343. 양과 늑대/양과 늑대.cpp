#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;
void connectEdges(vector<vector<int>>& edges,vector<vector<int>>& graph)
{
    for(auto x:edges)
    {
        int from = x[0];
        int to = x[1];
        graph[from].push_back(to);
    }
}

void dfs(vector<int>& info, vector<vector<int>>& graph, vector<int>& next, int sheep, int wolf, int cur)
{
    if(info[cur]) wolf++;
    else sheep++;
    
    if(wolf>=sheep) return;
    answer=sheep>answer?sheep:answer;
    
    for(int i=0;i<next.size();i++)
    {
        vector<int> tmp = next;
        tmp.erase(tmp.begin()+i);
        for(int j=0;j<graph[next[i]].size();j++)
        {
            tmp.push_back(graph[next[i]][j]);
        }
        dfs(info,graph,tmp,sheep,wolf,next[i]);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    
    int size = info.size();
    vector<vector<int>> graph(size);
    vector<int> next;
    connectEdges(edges,graph);
    
    // 0번 노드에서부터 시작
    for(int i=0;i<graph[0].size();i++){
        next.push_back(graph[0][i]);
    }
    
    dfs(info,graph,next,0,0,0);
    
    return answer;
}