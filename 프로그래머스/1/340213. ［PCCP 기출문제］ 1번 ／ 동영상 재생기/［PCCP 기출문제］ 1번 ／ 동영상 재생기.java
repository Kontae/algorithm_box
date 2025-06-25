
class Solution {
    
    public int convertToInt(String time) {
        String[] tmp = time.split(":");
        return Integer.parseInt(tmp[0])*60 + Integer.parseInt(tmp[1]);
    }
    
    public String convertToString(int time) {
        int minute = time / 60;
        int second = time % 60;
        return String.format("%02d:%02d",minute,second);
    }
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        String cur = pos;
        
        if(convertToInt(cur) >= convertToInt(op_start) && convertToInt(cur) <= convertToInt(op_end)) {
            cur = op_end;
        }
        
        for(String s : commands) {
            int time = convertToInt(cur);
            if(s.charAt(0)=='p') {
                if(time < 10) {
                    cur = convertToString(0);
                }
                else {
                    cur = convertToString(time - 10);
                }
            }
            else {
                if(time + 10 > convertToInt(video_len)) {
                    cur = video_len;
                }
                else {
                    cur = convertToString(time + 10);
                }
            }
            if(convertToInt(cur) >= convertToInt(op_start) && convertToInt(cur) <= convertToInt(op_end)) {
                cur = op_end;
            }
        }
        return cur;
    }

}