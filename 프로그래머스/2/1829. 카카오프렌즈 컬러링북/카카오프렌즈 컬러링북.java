class Solution {
    static boolean[][] visit;
    static int[] dx = {1,-1,0,0};
    static int[] dy = {0,0,1,-1};
    static int[][] map;
    static int m, n;
    static int count;
    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSize = 0;
        visit = new boolean[m][n];
        map = picture;
        this.m = m;
        this.n = n;
        
        for(int i=0;i<picture.length;i++) {
            for(int j=0;j<picture[0].length;j++) {
                if(visit[i][j] == false && map[i][j] != 0) {
                    numberOfArea++;
                    count = 0;
                    DFS(i, j);
                    maxSize = Math.max(maxSize, count);
                }
            }
        }
        
        return new int[]{numberOfArea, maxSize};
    }
    
    public static void DFS(int x, int y) {
        visit[x][y]=true;
        count++;
        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= m || ny >= n || nx < 0 || ny < 0 || visit[nx][ny] == true) continue;
            if(map[nx][ny] == map[x][y]) {
                DFS(nx, ny);
            }
        }
        
    }
}