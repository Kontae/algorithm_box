import java.util.*;
class Solution {
    public int[] solution(int k, int[] score) {
        List<Integer> result = new ArrayList<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int n : score) {
            pq.offer(n);
            if(pq.size()>k) {
                pq.poll();
            }
            result.add(pq.peek());
        }
        return result.stream().mapToInt(i->i).toArray();
    }
}