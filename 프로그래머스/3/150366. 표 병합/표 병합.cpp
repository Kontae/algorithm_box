#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;
int count = 0;
vector<string> solution(vector<string> commands) {
    vector<string> answer;
    vector<vector<pair<string,int>>> v(51,vector<pair<string,int>>(51,{"",0}));
    for(string &x: commands)
    {
        stringstream ss(x);
        string command;
        ss>>command;
        if(command=="UPDATE")
        {
            vector<string> params;
            string tmp;
            while(ss>>tmp)
            {
                params.push_back(tmp);
            }
            if(params.size()==3)
            {
                int r = stoi(params[0]);
                int c = stoi(params[1]);
                string s = params[2];
                // MERGE된 곳 없음
                if(v[r][c].second==0)
                {
                    v[r][c].first=s;
                }
                // MERGE된 곳 존재
                else
                {
                    for(int i=1;i<=50;i++)
                    {
                        for(int j=1;j<=50;j++)
                        {
                            if(v[i][j].second==v[r][c].second)
                            {
                                v[i][j].first=s;
                            }
                        }
                    }
                }
            }
            else
            {
                string s1 = params[0];
                string s2 = params[1];
                for(int i=1;i<=50;i++)
                    {
                        for(int j=1;j<=50;j++)
                        {
                            if(v[i][j].first==s1)
                            {
                                v[i][j].first=s2;
                            }
                        }
                    }
            }
        }
                else if(command=="MERGE")
        {
            int r1,c1,r2,c2;
            ss>>r1>>c1>>r2>>c2;
            if(r1==r2&&c1==c2) continue;
            string mergeValue = (v[r1][c1].first != "") ? v[r1][c1].first : v[r2][c2].first;
            if(v[r1][c1].second!=0&&v[r1][c1].second==v[r2][c2].second)
            {
                continue;
            }
            int newGroupId = ++count;
            if(v[r1][c1].second != 0)
            {
                int oldGroup = v[r1][c1].second;
                for(int i=1;i<=50;i++)
                {
                    for(int j=1;j<=50;j++)
                    {
                        if(v[i][j].second==oldGroup)
                        {
                            v[i][j].first=mergeValue;
                            v[i][j].second=newGroupId;
                        }
                    }
                }
            }
            else
            {
                v[r1][c1].first=mergeValue;
                v[r1][c1].second=newGroupId;
            }

            if(v[r2][c2].second!=0)
            {
                int oldGroup=v[r2][c2].second;
                for(int i=1;i<=50;i++)
                {
                    for(int j=1;j<=50;j++)
                    {
                        if(v[i][j].second == oldGroup)
                        {
                            v[i][j].first=mergeValue;
                            v[i][j].second=newGroupId;
                        }
                    }
                }
            }
            else
            {
                v[r2][c2].first=mergeValue;
                v[r2][c2].second=newGroupId;
            }
        }
        else if(command=="UNMERGE")
        {
            int r,c;
            ss>>r>>c;

            if(v[r][c].second==0) continue;

            string keepValue=v[r][c].first;
            int groupId=v[r][c].second;

            for(int i=1;i<=50;i++)
            {
                for(int j=1;j<=50;j++)
                {
                    if(v[i][j].second==groupId)
                    {
                        if(i==r&&j==c)
                        {
                            v[i][j].first=keepValue;
                        }
                        else
                        {
                            v[i][j].first="";
                        }
                        v[i][j].second=0;
                    }
                }
            }
        }
        else
        {
            int r,c;
            ss>>r>>c;
            answer.push_back(v[r][c].first==""?"EMPTY":v[r][c].first);
        }
    }

    return answer;
}