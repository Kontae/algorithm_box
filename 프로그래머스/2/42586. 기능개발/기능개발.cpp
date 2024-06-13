#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i=0;i<progresses.size();i++){
        if((100-progresses[i])%speeds[i]!=0) q.push((100-progresses[i])/speeds[i]+1);
        else q.push((100-progresses[i])/speeds[i]);
    }
    
    while(!q.empty())
    {
        int tmp = q.front();
        int cnt = 1;
        q.pop();
        while(q.front()<=tmp && !q.empty())
        {
            q.pop();
            cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}


