class Solution {
    public int solution(int a, int b, int n) {
        int answer = 0;
        
        while(n>=a) {
            int newCoke = n / a * b ;
            int mod = n % a;
            answer += newCoke;
            n = newCoke + mod;
        }
        return answer;
    }
}