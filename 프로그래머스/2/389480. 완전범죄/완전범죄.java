import java.util.*;
class Solution {
    public int solution(int[][] info, int n, int m) {
        int answer = 0;
        Arrays.sort(info,(a,b)->a[1]-b[1]);
        for(int[] x : info) {
            if(m>x[1]) {
                m-=x[1];
            }
            else if(n>x[0]) {
                n-=x[0];
                answer+=x[0];
            }
            else {
                return -1;
            }
        }
        return answer;
    }
}