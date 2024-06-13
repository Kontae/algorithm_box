#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> s;
    for(auto x: nums){
        s.insert(x);
    }
    for(auto it=s.begin();it!=s.end();it++)
    {
        answer++;
    }
    if(answer>nums.size()/2) answer=nums.size()/2;
    return answer;
}