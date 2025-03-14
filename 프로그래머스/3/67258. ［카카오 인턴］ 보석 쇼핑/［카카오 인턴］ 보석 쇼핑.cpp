#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    unordered_map<string,int> map;
    int allGemCount = 0;
    int gemCount=0;
    int start = 0;
    int end = 0;
    int minLen = 100000;
    for(auto& x: gems)
    {
        if(map[x]==0)
        {
            allGemCount++;
        }
        map[x]++;
    }
    map.clear();
    while(true)
    {
        if(gemCount==allGemCount)
        {
            if(end-start<minLen)
            {
                answer[0]=start+1;
                answer[1]=end;
                minLen=end-start;
            }
            if(map[gems[start]]<=1) gemCount--; 
            map[gems[start]]--;
            start++;
        }
        else
        {
            if(end>=gems.size()) break;
            if(!map[gems[end]]) gemCount++;
            map[gems[end]]++;
            end++;
        }
    }
    return answer;
}