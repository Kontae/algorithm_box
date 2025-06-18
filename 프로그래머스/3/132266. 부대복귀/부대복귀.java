import java.util.*;
class Solution {
    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        ArrayList<Integer> answer = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();
        int[] dist = new int[n+1];
        Arrays.fill(dist,-1);
        ArrayList<Integer>[] graph = new ArrayList[n+1];
        for(int i=0;i<=n;i++) {
            graph[i] = new ArrayList<>();
        }
        for(int[] x : roads)
        {
            graph[x[0]].add(x[1]);
            graph[x[1]].add(x[0]);
        }
        
        q.offer(destination);
        dist[destination] = 0;
        
        while(!q.isEmpty()) {
            int cur = q.poll();
            for(int next : graph[cur]) {
                if(dist[next] == -1) {
                    dist[next] = dist[cur] + 1;
                    q.offer(next);
                }
            }
        }
        
        for(int start : sources) {
            answer.add(dist[start]);
        }
        return answer.stream().mapToInt(i->i).toArray();
    }
}