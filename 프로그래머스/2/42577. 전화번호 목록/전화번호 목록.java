import java.util.*;
class Solution {
    public boolean solution(String[] phone_book) {
        Arrays.sort(phone_book,(a,b)-> a.length()-b.length());
        
        Set<String> set = new HashSet<>();
        
        for(String number : phone_book) {
            String s = "";
            for(int i = 0; i < number.length(); i++) {
                s += number.charAt(i);
                if(set.contains(s)) {
                return false;
                }
            }
            set.add(number);
        }
        
        return true;
    }
}