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

void dfs(vector<vector<int>>& graph, vector<int>& info, int visit, int sheep, int wolf)
{
    if(sheep<=wolf) return;
    answer=answer>sheep?answer:sheep;
    
    for(int i=0;i<info.size();i++)
    {
        if(visit&(1<<i))
        {
            for(int next : graph[i])
            {
                if(!(visit & (1 << next)))
                {
                    int nextSheep = sheep + (info[next]==0);
                    int nextWolf = wolf + (info[next]==1);
                    dfs(graph,info,visit | (1<<next),nextSheep,nextWolf);
                }
            }
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    
    vector<vector<int>> graph(info.size());
    connectGraph(graph,edges);
    
    int initialVisited = 1;
    int initialSheep = info[0] == 0 ? 1 : 0;
    int initialWolf = info[0] == 1 ? 1 : 0;
                              
    dfs(graph,info,initialVisited,initialSheep,initialWolf);
    
    return answer;
}