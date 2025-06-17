import java.util.*;
class Solution {
    public int solution(int[] ingredient) {
        int answer = 0;
        Stack<Integer> st = new Stack<>();
        for(int i : ingredient) {
            st.push(i);
            if(st.size()>=4) {
                int size = st.size();
                if(st.get(size-1) == 1 && st.get(size-2) == 3 && st.get(size-3) == 2 && st.get(size-4) == 1) {
                    st.pop(); st.pop(); st.pop(); st.pop();
                    answer++;
                }
            }
        }
        return answer;
    }
}