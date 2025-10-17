import java.util.*;
class Solution {
    public long solution(int n, int[] times) {
        long answer = 0;
        long min = 1;
        long max = (long)Arrays.stream(times).max().getAsInt() * n;
        
        while(min <= max) {
            long mid = (min + max) / 2;
            long completed_people = 0;
            
            for(int t : times) {
                completed_people += (mid / t);
            }
            
            if(completed_people >= n) {
                max = mid - 1;
                answer = mid;
            }
            else {
                min = mid + 1;
            }    
        }
        return answer;
    }
}