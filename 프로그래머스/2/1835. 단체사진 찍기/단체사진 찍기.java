class Solution {
    char[] name = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    boolean[] visited = new boolean[8];
    String[] arr;
    int answer = 0;
    
    public int solution(int n, String[] data) {
        arr = data;
        generatePermutation(0, new StringBuilder());
        return answer;
    }
    
    private void generatePermutation(int count, StringBuilder sb) {
        if(count==8) {
            if(checkLine(sb.toString())) answer++;
            return;
        }
        
        for(int i=0;i<8;i++) {
            if(!visited[i]) {
                visited[i] = true;
                sb.append(name[i]);
                generatePermutation(count + 1, sb);
                sb.deleteCharAt(sb.length()-1);
                visited[i] = false;
            }
        }
        
    }
    
    private boolean checkLine(String line) {
        for(String s : arr) {
            char from = s.charAt(0);
            char to = s.charAt(2);
            char oper = s.charAt(3);
            int distance = Math.abs(line.indexOf(to) - line.indexOf(from)) - 1;
            int value = s.charAt(4)-'0';
            if(oper == '=') {
                if(distance != value) {
                    return false;
                }
            }
            else if(oper == '<') {
                if(distance >= value) {
                    return false;
                }
            }
            else {
                if(distance <= value) {
                    return false;
                }
            }
        }
        return true;
    }
}