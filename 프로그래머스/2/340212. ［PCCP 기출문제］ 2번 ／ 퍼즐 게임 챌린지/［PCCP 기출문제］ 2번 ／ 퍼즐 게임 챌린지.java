class Solution {
    int[] diffs;
    int[] times;
    long limit;
    public int solution(int[] diffs, int[] times, long limit) {
        this.diffs = diffs;
        this.times = times;
        this.limit = limit;
        int answer = 0;
        
        int min = 1;
        int max = 100000;
        
        while(min <= max) {
            int mid = (min + max) / 2;
            if(isPossible(mid)) {
                answer = mid;
                max = mid - 1;
            }
            else {
                min = mid + 1;
            }
        }
        return answer;
    }
    private Boolean isPossible (int level) {
        long total_time = 0;
        for(int i = 0; i< diffs.length; i++) {
            int diff = diffs[i];
            int time_cur = times[i];
            if(diff <= level) {
                total_time += time_cur;
            }
            else {
                int gap = diff - level;
                total_time += (time_cur + times[i-1]) * gap + time_cur;
            }
            if(total_time > limit) {
                return false;
            }
        }
        
        return true;
    }
}