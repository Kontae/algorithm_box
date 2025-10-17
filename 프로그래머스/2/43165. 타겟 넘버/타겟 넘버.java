class Solution {
    private int[] numbers;
    private int target;
    private int answer;
    
    public int solution(int[] numbers, int target)
    {
        this.numbers = numbers;
        this.target = target;
        
        DFS(0,0);
        return answer;
    }
    
    public void DFS(int sum, int depth) {
        if(depth == numbers.length) {
            if(sum == target) {
                answer++;
            }
            return;
        }
        
        DFS(sum + numbers[depth], depth+1);
        DFS(sum - numbers[depth], depth+1);
    }
}