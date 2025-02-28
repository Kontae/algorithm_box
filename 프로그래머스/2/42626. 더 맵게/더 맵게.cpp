#include <string>
#include <vector>
#include <queue>
using namespace std;
struct cmp{
    bool operator()(int& a, int& b){
        return a>b;
    }
};

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,cmp> pq;
    
    for(auto &x: scoville){
        pq.push(x);
    }
    if(pq.top()>=K){
        return 0;
    }
    
    while(!pq.empty()){
        answer++;
        int first=pq.top();
        pq.pop();
        int second=pq.top();
        pq.pop();
        pq.push(first+second*2);
        if(pq.top()<K&&pq.size()==1) return -1;
        if(pq.top()>=K) break;
    }
    return answer;
}