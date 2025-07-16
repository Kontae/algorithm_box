import java.util.Arrays;
class Solution {
    boolean[][] visit = new boolean[5][5];
    int[] dx = {1, -1, 0, 0};
    int[] dy = {0, 0, 1, -1};
    public int[] solution(String[][] places) {
        int[] answer = {1, 1, 1, 1 ,1};
        for(int k = 0; k < 5; k++) {
            boolean flag = true;
            for(int i = 0; i < 5 && flag; i++) {
                for(int j = 0; j < 5 && flag; j++) {
                    if(places[k][i].charAt(j) == 'P') {
                        if(!check(places[k], i, j, 0)) {
                            answer[k] = 0;
                            flag = false;
                        }
                    }
                }
            }
            initVisit();
        }
        return answer;
    }
    
    private boolean check(String[] place, int x, int y, int depth) {
        if(depth == 2) {
            return true;
        }
        visit[x][y] = true;
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || visit[nx][ny] == true || place[nx].charAt(ny) == 'X') continue;
            if(place[nx].charAt(ny) == 'P') return false;
            if(place[nx].charAt(ny) == 'O') {
                if(!check(place, nx, ny, depth + 1)) {
                    return false;
                }
            }
        }
        return true;
    }
    
    private void initVisit() {
        for (int i = 0; i < visit.length; i++) {
            Arrays.fill(visit[i], false);
        }
    }
}