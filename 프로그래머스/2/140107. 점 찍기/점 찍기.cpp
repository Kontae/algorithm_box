#include <string>
#include <vector>
#include <cmath>
using namespace std;


long long solution(int k, int d) {
    long long answer = d/k+1;
    for(int i=0;i<d;i+=k)
    {
        answer+=(long long)sqrt((long long)d*d-(long long)i*i)/k;
    }
    
    return answer;
}