import java.util.HashMap;
class Solution {
    public String solution(String X, String Y) {
        StringBuilder answer = new StringBuilder();
        HashMap<Character,Integer> mapX = new HashMap<>();
        HashMap<Character,Integer> mapY = new HashMap<>();
        for(char c : X.toCharArray()) {
            mapX.put(c,mapX.getOrDefault(c,0)+1);
        }
        for(char c : Y.toCharArray()) {
            mapY.put(c,mapY.getOrDefault(c,0)+1);
        }
        
        for(HashMap.Entry<Character,Integer> entry : mapX.entrySet()) {
            char xC = entry.getKey();
            int xNum = entry.getValue();
            int yNum = mapY.getOrDefault(xC,0);
            
            int count = xNum < yNum ? xNum : yNum;
            for(int i=0;i<count;i++)    answer.append(xC);
        }
        if(answer.length()==0) return "-1";
        if(answer.charAt(answer.length()-1)=='0') return "0";
        return answer.reverse().toString();
    }
}