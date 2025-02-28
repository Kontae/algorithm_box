#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
ll solution(int n, vector<int> times) {
    ll answer = 0;
    ll min = 1;
    ll max = *max_element(times.begin(),times.end())*(ll)n;
    
    while(min<=max){
        ll mid = (min + max) / 2;
        ll people = 0;
        
        for(auto x: times){
            people += (mid/x);
        }
        if(people>=n){
            max = mid - 1;
            answer = mid;
        }
        else{
            min = mid + 1;
        }
    }
    
    
    return answer;
}
