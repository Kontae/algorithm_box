import java.util.*;
class Solution {
    int n, m;
    String[] map;
    int[] dx = {1,-1,0,0};
    int[] dy = {0,0,1,-1};
    boolean[][] visit;
    public int[] solution(String[] maps) {
        n = maps.length;
        m = maps[0].length();
        map = maps;
        visit = new boolean[n][m];
        
        List<Integer> answer = new ArrayList<>();
        for(int i=0;i<maps.length;i++) {
            for(int j=0;j<maps[0].length();j++) {
                if(!visit[i][j]&&maps[i].charAt(j)!='X') {
                    answer.add(DFS(i,j));
                }
            }
        }
        
        if(answer.size()==0) answer.add(-1);
        return answer.stream().sorted().mapToInt(i->i).toArray();
    }
    
    private int DFS(int x, int y) {
        visit[x][y] = true;
        int sum = map[x].charAt(y)-'0';
        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && !visit[nx][ny] && map[nx].charAt(ny) != 'X') {
                sum += DFS(nx,ny);
            }
        }
        return sum;
    }
}