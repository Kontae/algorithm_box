import java.util.*;

class Solution {
    public String[] solution(String[][] plans) {
        List<String> answer = new ArrayList<>();
        Stack<String[]> st = new Stack<>();
        Arrays.sort(plans,(a,b)->a[1].compareTo(b[1]));
        
        for(int i = 0; i < plans.length - 1; i++) {
            String name = plans[i][0];
            String time = plans[i][1];
            int playingTime = Integer.parseInt(plans[i][2]);
            String nextTime = plans[i+1][1];
            
            int endMin = toMinutes(time) + playingTime;
            int nextMin = toMinutes(nextTime);
            
            // 먼저 하고 있었던 작업을 멈춰야할 때
            if(endMin > nextMin) {
                st.push(new String[]{name, String.valueOf(endMin - nextMin)});
            }
            // 시간 여유 될 때
            else {
                answer.add(name);
                int spareTime = nextMin - endMin;
                
                while(!st.isEmpty() && spareTime > 0) {
                    String[] val = st.pop();
                    int remainTime = Integer.parseInt(val[1]);
                    
                    // 여분 시간에 전부 처리 가능할 때
                    if(remainTime <= spareTime) {
                        answer.add(val[0]);
                        spareTime -= remainTime;
                    }
                    else {
                        st.push(new String[]{val[0], String.valueOf(remainTime - spareTime)});
                        break;
                    }
                }
            }
        }
        answer.add(plans[plans.length-1][0]);
        
        while(!st.isEmpty()) {
            answer.add(st.pop()[0]);
        }
        
        return answer.toArray(new String[0]);
    }
    
    private int toMinutes(String time) {
        return Integer.parseInt(time.substring(0,2)) * 60 + Integer.parseInt(time.substring(3));
    }
}