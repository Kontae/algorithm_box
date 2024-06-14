#include <string>
#include <vector>

using namespace std;
bool visit[201];
void DFS(vector<vector<int>> &computers, int cur)
{
    visit[cur]=true;
    for(int i=0;i<computers.size();i++)
    {
        if(!visit[i]&&computers[cur][i]==1)
        {
            DFS(computers,i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;i++)
    {
        if(!visit[i])
        {
            DFS(computers,i);
            answer++;
        }
    }
    return answer;
}