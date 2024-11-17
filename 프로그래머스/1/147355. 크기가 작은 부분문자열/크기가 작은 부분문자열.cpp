#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int t_length = t.length();
    int p_length = p.length();
    
    for(int i=0;i<t_length-p_length+1;i++){
        string s = "";
        for(int j=0;j<p_length;j++){
             s+=t[i+j];
        }
        long long num = stoll(s);
        if(num<=stoll(p)){
            answer++;
        }
        
    }
    return answer;
}