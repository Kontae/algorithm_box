#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int,int> total,chul;
    for(auto x: topping)
    {
        total[x]++;
    }
    int toppingCount = total.size();
    for(auto x: topping)
    {
        chul[x]++;
        total[x]--;
        if(total[x]==0) toppingCount--;
        if(chul.size()==toppingCount) answer++;
    }
    return answer;
}