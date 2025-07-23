import java.util.*;
class Solution {
    public int solution(int[] picks, String[] minerals) {
        int answer = 0;
        List<String[]> arr = new ArrayList<>();
        int[][] cost = {{1, 1, 1}, {5, 1, 1}, {25, 5, 1}};
        Map<String, Integer> map = Map.of("diamond", 0, "iron", 1 , "stone", 2);
        int maxLength = Math.min((picks[1] + picks[2] + picks[0]) * 5, minerals.length);
        for(int i = 0; i < maxLength; i += 5) {
            int size = Math.min(maxLength - i, 5);
            String[] group = new String[size];
            for(int j = 0; j < 5 && i + j < maxLength ; j++) {
                group[j] = minerals[i + j];
            }
            arr.add(group);
        }
        
        arr.sort((a,b) -> {
            int diaA = countSum(a,"diamond");
            int diaB = countSum(b,"diamond");
            if(diaA != diaB) {
                return diaB - diaA;
            }
            
            int ironA = countSum(a, "iron");
            int ironB = countSum(b, "iron");
            return ironB - ironA;
        });
        
        
        for(String[] x : arr) {
            int idx = -1;
            for(int i = 0; i < 3; i++) {
                if(picks[i] != 0) {
                    picks[i]--;
                    idx = i;
                    break;
                }
            }
            if(idx == -1) break;
            for(String s : x) {
                answer += cost[idx][map.get(s)];
            }
        }
        
        return answer;
    }
    
    private int countSum(String[] arr, String type) {
        int cnt = 0;
        for(String x : arr) {
            if(x.equals(type)) {
                cnt++;
            }
        }
        return cnt;
    }
}