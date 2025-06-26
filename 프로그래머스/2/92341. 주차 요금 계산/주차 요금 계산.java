import java.util.*;
class Solution {
    public int convertToI(String time) {
        String[] tmp = time.split(":");
        return Integer.parseInt(tmp[0])*60 + Integer.parseInt(tmp[1]);
    }
    
    public int[] solution(int[] fees, String[] records) {
        Map<String, Integer> inTime = new HashMap<>();
        Map<String, Integer> total = new HashMap<>();
        
        for(String s: records) {
            String[] tmp = s.split(" ");
            Integer time = convertToI(tmp[0]);
            String number = tmp[1];
            String type = tmp[2];
            if(type.equals("IN")) {
                inTime.put(number,time);
            }
            else {
                Integer parkedTime = time - inTime.get(number);
                total.put(number, total.getOrDefault(number,0) + parkedTime);
                inTime.remove(number);
            }
        }
        
        int end = convertToI("23:59");
        for(String number : inTime.keySet()) {
            Integer parkedTime = end - inTime.get(number);
            total.put(number,total.getOrDefault(number,0) + parkedTime);
        }
        
        List<String> car = new ArrayList<>(total.keySet());
        Collections.sort(car);
        
        int[] answer = new int[car.size()];
        for(int i=0;i<car.size();i++) {
            String number = car.get(i);
            int time = total.get(number);
            int fee = fees[1];
            if(time>fees[0]) {
                fee += Math.ceil((double)(time - fees[0])/fees[2]) * fees[3];
            }
            answer[i] = fee;
        }
        return answer;
    }
}