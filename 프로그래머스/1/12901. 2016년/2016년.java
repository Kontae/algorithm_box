class Solution {
    public String solution(int a, int b) {
        String[] days = {"THU","FRI","SAT","SUN","MON","TUE","WED"};
        int[] day = {31,29,31,30,31,30,31,31,30,31,30,31};
        int num = b;
        for(int i=0;i<a-1;i++) {
            num+=day[i];
        }
        return days[num%7];
    }
}