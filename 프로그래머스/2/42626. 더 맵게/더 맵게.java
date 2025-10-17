import java.util.*;
class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int x : scoville) {
            pq.offer(x);
        }
        
        while(pq.peek() < K) {
            if(pq.size() < 2) {
                return -1;
            }
            int first = pq.poll();
            int second = pq.poll();
            
            pq.offer(first + 2 * second);
            answer++;
        }
        return answer;
    }
}