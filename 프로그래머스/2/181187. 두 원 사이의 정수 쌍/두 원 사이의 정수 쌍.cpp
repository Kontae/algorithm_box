#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
long long OutsideCalc(int r)
{
    long long cnt = r;
    for(int i=1;i<r;i++)
        cnt += (long long)sqrt(1LL*r*r - 1LL*i*i);
    return cnt*4+1;
}
long long InsideCalc(int r)
{
    long long cnt = r - 1;
    for(int i=1;i<r;i++)
    {
        long long tmp = (long long)sqrt(1LL*r*r - 1LL*i*i);
        if(tmp*tmp + 1LL*i*i == 1LL*r*r) cnt += tmp - 1;
        else cnt += tmp;
    }
    return cnt*4+1;
}
long long solution(int r1, int r2) {
    long long cnt1=0,cnt2=0;
    cnt1=OutsideCalc(r2);
    cnt2=InsideCalc(r1);
    
    cout<<cnt1<<" "<<cnt2<<'\n';
    return cnt1-cnt2;
}