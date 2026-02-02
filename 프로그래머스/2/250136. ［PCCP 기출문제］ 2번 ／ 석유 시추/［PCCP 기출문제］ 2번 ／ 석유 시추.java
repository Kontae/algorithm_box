import java.util.*;
class Solution {
    int[][] land;
    int oilFlag = 2;
    int n, m;
    int[] dx = {1, -1, 0, 0};
    int[] dy = {0, 0, 1, -1};
    public int solution(int[][] land) {
        this.land = land;
        this.n = land.length;
        this.m = land[0].length;
        Map<Integer, Integer> map = new HashMap<>();
        int answer = -1;
        
        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(land[j][i] == 1) {
                    int sum = BFS(j, i);
                    map.put(oilFlag, sum);
                    oilFlag++;
                }
            }
        }
        
        for(int i = 0; i < m; i++) {
            Set<Integer> set = new HashSet<>();
            int resultSum = 0;
            for(int j = 0; j < n; j++) {
                // 석유 덩어리일 경우
                if(land[j][i] > 1) {
                    // 중복 방지
                    set.add(land[j][i]);
                }
            }
            
            for(Integer oFlag : set) {
                resultSum += map.get(oFlag);
            }
            if(answer < resultSum) {
                answer = resultSum;
            }
        }
        
        return answer;
    }
    
    private int BFS(int x, int y) {
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{x, y});
        land[x][y] = oilFlag;
        int count = 1;
        
        while(!q.isEmpty()) {
            int[] cur = q.poll();
            int cx = cur[0];
            int cy = cur[1];
            
            for(int i = 0 ;i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && land[nx][ny] == 1) {
                    q.offer(new int[]{nx,ny});
                    land[nx][ny] = oilFlag;
                    count++;
                }
            }
        }
        return count;
    }
}