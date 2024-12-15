class Solution {
    public int solution(int n) {
        int answer = 0;
        for(int i=1;i<=(int)Math.sqrt(n);i++){
            if(n%i==0){
                answer+=(i+n/i);
            }
            if(i==Math.sqrt(n)){
                answer-=i;
            }
        }
        return answer;
    }
}