#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//선물 주고받은 표  |  n이 m에게 선물 줌
int gift[51][51];
//선물 지수
int gift_value[51];
int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int size=friends.size();
    //선물표 입력
    for(auto x:gifts)
    {
        string from=x.substr(0,x.find(' '));
        string to=x.substr(x.find(' ')+1);
        auto it1=find(friends.begin(),friends.end(),from);
        auto it2=find(friends.begin(),friends.end(),to);
        int n=it1-friends.begin();
        int m=it2-friends.begin();
        gift[n][m]++;
    }
    //선물 지수 +
    for(int i=0;i<friends.size();i++)
    {
        for(int j=0;j<friends.size();j++)
        {
            gift_value[i]+=gift[i][j];    
        }
    }
    //선물 지수 -
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            gift_value[i]-=gift[j][i];
        }
    }
    
    for(int i=0;i<size;i++)
    {
        int cnt=0;
        for(int j=0;j<size;j++)
        {
            if(i==j) continue;
            if(gift[i][j]>gift[j][i]) cnt++;
            else if(gift[i][j]==gift[j][i])
            {
                if(gift_value[i]>gift_value[j]) cnt++;
            }
        }
        answer=answer>cnt?answer:cnt;
    }
    return answer;
}