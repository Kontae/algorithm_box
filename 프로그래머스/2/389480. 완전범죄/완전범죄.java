import java.util.*;
class Solution {
    public int solution(int[][] info, int n, int m) {
        // dp[i][j] => i번째 인덱스에서 a가 j만큼 흔적을 남겼을 때 b 흔적의 최소 개수 
        int[][] dp = new int[info.length+1][n];
        for(int i=0;i<=info.length;i++) {
            Arrays.fill(dp[i],Integer.MAX_VALUE);
        }
        dp[0][0] = 0;
        for(int i=1;i<=info.length;i++) {
            for(int a=0;a<n;a++) {
                if(dp[i-1][a]==Integer.MAX_VALUE) continue;
                int traceA = a+info[i-1][0];
                if(traceA<n) {
                    // 주체가 b 흔적의 최소 개수이므로, dp[i-1][a](바로 전)와 비교
                    dp[i][traceA] = Math.min(dp[i][traceA],dp[i-1][a]);
                }
                int traceB = dp[i-1][a] + info[i-1][1];
                if(traceB<m) {
                    // b가 늘어났으므로, traceB와 비교
                    dp[i][a] = Math.min(traceB,dp[i][a]);
                }
            }
        }
        
        for(int i=0;i<n;i++) {
            if(dp[info.length][i] < m) {
                return i;
            }
        }
        return -1;
    }
}