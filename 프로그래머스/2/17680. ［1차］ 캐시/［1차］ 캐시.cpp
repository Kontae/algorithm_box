#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> dq;

    for(auto &x : cities) {
        transform(x.begin(),x.end(),x.begin(),::tolower);   
    }
    
    for(auto &c: cities) {
        int hitIdx = -1;
        for(int i=0;i<dq.size();i++) {
            if(c == dq[i]) {
                hitIdx = i;
                break;
            }
        }
        dq.push_back(c);
        
        if(hitIdx == -1) {
            if(dq.size() > cacheSize) {
                dq.pop_front();
            }
            answer += 5;
        }
        else {
            dq.erase(dq.begin() + hitIdx);
            answer++;
        }
    }

    return answer;
}