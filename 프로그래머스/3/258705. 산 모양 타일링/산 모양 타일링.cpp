#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int MOD = 10007;

int solution(int n, vector<int> tops) {
    vector<vector<int>> dp(n+1, vector<int>(2, 0));
    
    // dp 초기화
    dp[0][0] = 1;
    dp[0][1] = 0;
    
    for(int i = 0; i < n; i++) {
        // 현재 위치에 삼각형 존재 X
        if(tops[i] == 0) {
            // 삼각형 존재하지 않을 땐 dp[i][0] => 사다리꼴 칠하거나 그냥 냅두거나 (2) / dp[i][1] => 삼각형 하나밖에 안 남아서 한 가지밖에 없음 (1)
            dp[i+1][0] = (dp[i][0] * 2 + dp[i][1]) % MOD;
            // dp[i+1][0]과 겹치지 않으면서 맨 오른쪽 삼각형이 색칠되어 있을 경우 => 한 가지
            dp[i+1][1] = (dp[i][0] + dp[i][1]) % MOD;
        }
        else {
            // 삼각형 존재할 땐 dp[i][0] => 삼각형 3개 남음 => 3가지 / dp[i][1] => 삼각형 2개 남음 => 2가지
            dp[i+1][0] = (dp[i][0] * 3 + dp[i][1] * 2) % MOD;
            dp[i+1][1] = (dp[i][0] + dp[i][1]) % MOD;
        }
    }
    
    return (dp[n][0] + dp[n][1]) % MOD;
}