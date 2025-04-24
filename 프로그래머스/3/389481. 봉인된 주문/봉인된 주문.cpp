#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
typedef long long ll;

using namespace std;

ll convertStoI(string s)
{
    ll result=0;
    int idx=0;
    for(int i=s.size()-1;i>=0;i--)
    {
        char ch=s[i];
        result+=(ch-'a'+1)*pow(26,idx);
        idx++;
    }
    return result;
}

string convertItoS(ll n)
{
    string s="";
    ll tmp=0;
    while(n>0)
    {
        tmp=(n-1)%26;
        s+=tmp+'a';
        n= (n-1)/26;
    }
    reverse(s.begin(),s.end());
    return s;
}
string solution(long long n, vector<string> bans) {
    string answer = "";
    ll answerNum = 0;
    vector<ll> v;
    for(auto &x: bans)
    {
        v.push_back(convertStoI(x));
    }
    
    sort(v.begin(),v.end());
    
    for(auto y: v)
    {
        if(y<=n) n++;
        else break;
    }
    answer = convertItoS(n);
    return answer;
}