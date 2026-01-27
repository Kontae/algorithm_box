class Solution {
    public int solution(int[] schedules, int[][] timelogs, int startday) {
        int answer = 0;
        for(int i = 0 ; i < timelogs.length ; i++) {
            int hopeTime = schedules[i];
            Boolean flag = true;
            int admittedTime = getAdmittedTime(schedules[i]);
            
            for(int j = 0 ; j < timelogs[i].length; j++) {
                if(j == 6 - (startday % 7) || j == 7 - startday) {
                    continue;
                }
                int arrivedTime = timelogs[i][j];
                if(arrivedTime > admittedTime) {
                    flag = false;
                    break;
                }
            }
            
            if(flag) {
                answer++;
            }
        }
        return answer;
    }
    
    private int getAdmittedTime (int arriveTime) {
        int hour = arriveTime / 100;
        int minute = arriveTime % 100;
        if(minute >= 50) {
            hour += 1;
            minute -= 60;
        }
        return hour * 100 + minute + 10;
    }
}