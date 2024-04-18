#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int cnt[60*24+10];
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<pair<int,int>> v;
    for(int i=0;i<book_time.size();i++)
    {
        int startTime=60*stoi(book_time[i][0].substr(0,2))+stoi(book_time[i][0].substr(3,2));
        int endTime= 60*stoi(book_time[i][1].substr(0,2))+stoi(book_time[i][1].substr(3,2))+9;
        v.push_back({startTime,endTime});
    }
    for(auto x:v)
    {
        for(int i=x.first;i<=x.second;i++)
        {  
            cnt[i]++;
        }
    }
    answer=*max_element(cnt,cnt+(60*24+10));
    return answer;
}