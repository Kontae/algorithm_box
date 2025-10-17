import java.util.*;
class Solution {
    public int solution(int[][] maps) {
        int answer = 0;
        
        int[] dx = {0,0,-1,1};
        int[] dy = {1,-1,0,0};
        Queue<int[]> q = new LinkedList<>();
        boolean[][] visited = new boolean[101][101];
        int n = maps.length;
        int m = maps[0].length;
        
        q.offer(new int[]{0,0,1});
        visited[0][0] = true;
        
        while(!q.isEmpty())
        {
            int[] cur = q.poll();
            int cx = cur[0];
            int cy = cur[1];
            int dist = cur[2];
            
            if(cx == n-1 && cy == m-1) {
                return dist;
            }
            
            for(int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    if(!visited[nx][ny] && maps[nx][ny] == 1) {
                        visited[nx][ny] = true;
                        q.offer(new int[]{nx, ny, dist + 1});
                    }
                }
            }
        }
        return -1;
    }
}