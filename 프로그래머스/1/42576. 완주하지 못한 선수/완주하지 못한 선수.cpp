#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> m;
    for(auto x: participant){
        m[x]++;
    }
    for(auto x:completion){
        m[x]--;
    }
    vector<pair<string,int>> v(m.begin(),m.end());
    for(auto x:v){
        if(x.second==1) answer=x.first;
    }
    return answer;
}