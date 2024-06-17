#include <string>
#include <vector>
#include <queue>
using namespace std;


int solution(int n, int k, vector<int> enemy) {
    int answer = -1;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<enemy.size();i++)
    {
        pq.push(enemy[i]);
        if(pq.size()>k)
        {
            n-=pq.top();
            pq.pop();
        }
        if(n<0) {
            answer=i;
            break;
        }
    }
    if(answer==-1) answer=enemy.size();
    return answer;
}