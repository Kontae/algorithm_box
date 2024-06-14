#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll solution(int n, vector<int> times) {
    ll answer = 0;
    ll max=(*max_element(times.begin(),times.end()))*(ll)n;
    //최대 : 제일 오래걸리는 심사관 * n명 의 시간
    ll min=1;
    //최소 : 1
    while(min<=max)
    //이분탐색 시작
    {
        ll mid=(min+max)/2;
        ll sum=0;
        //심사받을 수 있는 사람 수
        
        for(auto x:times)
        {
            sum+=(mid/x);
            //  총 시간 / 검사걸리는 시간 
            //  => 시간 안에 검사관에게 검사받을 수 있는 사람 의 수
        }
        if(sum>=n)
        //모두 심사받을 수 있으면
        {
            max=mid-1;
            //max값 줄여서 절반으로 줄임
            answer=mid;
            //answer값 갱신
        }
        else
        //그 시간대에는 심사 다 못받음 => 최솟값 늘려야함
        {
            min=mid+1;
        }
    }
    return answer;
}