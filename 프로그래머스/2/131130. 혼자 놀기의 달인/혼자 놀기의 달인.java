import java.util.*;
class Solution {
    public int solution(int[] cards) {
        int answer = 0;
        Queue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        boolean[] visit = new boolean[cards.length];
        for(int i = 0 ; i < cards.length ; i++) {
            int count = 0;
            if(visit[i]==true) continue;
            int idx = cards[i]-1;
            while(!visit[idx]) {
                visit[idx] = true;
                idx = cards[idx]-1;
                count++;
            }
            pq.offer(count);
        }
        if(pq.size()< 2) return 0;
        return pq.poll() * pq.poll();
    }
}