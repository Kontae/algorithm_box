import java.util.*;
class Solution {
    static List<List<Integer>> graph;
    static int dp[][];
    public int solution(int n, int[][] lighthouse) {
        graph = new ArrayList<>();
        dp = new int[n+1][2];
        for(int i=0;i<n+1;i++) {
            graph.add(new ArrayList<>());
        }
        for(int[] edge : lighthouse) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        
        dfs(1,0);
        return Math.min(dp[1][0],dp[1][1]); 
    }
    
    private void dfs(int node, int prev) {
        dp[node][0] = 0;
        dp[node][1] = 1;
        for(int next : graph.get(node)) {
            if(next == prev) continue;
            dfs(next, node);
            dp[node][0] += dp[next][1];
            dp[node][1] += Math.min(dp[next][0], dp[next][1]);
        }
    }
}