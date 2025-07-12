import java.util.*;
class Solution {
    HashMap<String,Integer> map = new HashMap<String,Integer>();
    public int solution(String[] babbling) {
        int answer = 0;
        initWords();
        
        for(String s : babbling) {
            if(checkBabbling(s)) answer++;
        }
        return answer;
    }
    
    private void initWords() {
        map.put("aya",1);
        map.put("ye",1);
        map.put("woo",1);
        map.put("ma",1);
    }
    
    private boolean checkBabbling(String s) {
        StringBuilder sb = new StringBuilder();
        String prev = "1";
        int count = 0;
        for(int i = 0; i < s.length(); i++, count++) {
            sb.append(s.charAt(i));
            int tmp = map.getOrDefault(sb.toString(),0);
            if(tmp == 1 && !sb.toString().equals(prev)) {
                prev = sb.toString();
                sb.setLength(0);
                count = 0;
            }
            if((tmp == 0 && count >3)) return false;
        }
        if(sb.length() == 0)  {
            return true;
        }
        return false;
    }
}