#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(pair<pair<int,int>,int> A, pair<pair<int,int>,int> B)
{
    if(A.first.first+A.first.second==B.first.first+B.first.second) return A.second<B.second;
    return A.first.first+A.first.second>B.first.first+B.first.second;
}

int solution(vector<vector<int>> scores) {
    int tmp = 0;
    // {{scores[0],scores[1]},idx}
    vector<pair<pair<int,int>,int>> v;
    for(int i=0;i<scores.size();i++)
    {
        v.push_back({{scores[i][0],scores[i][1]},i});
    }
    
    sort(v.begin(),v.end(),cmp);
    
    for(int i=0;i<v.size();i++)
    {
        int score1 = v[i].first.first;
        int score2 = v[i].first.second;
        
        for(int j=0;j<i;j++)
        {
            int prev_score1 = v[j].first.first;
            int prev_score2 = v[j].first.second;
            if(score1<prev_score1 && score2<prev_score2)
            {
                if(v[i].second==0) return -1;
                tmp++;
                break;
            }
        }
        if(v[i].second==0) return i+1-tmp;
    }
}