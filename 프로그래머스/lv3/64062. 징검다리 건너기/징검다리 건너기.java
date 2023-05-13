import java.util.*;

class Solution {
    
    private static class Stone{
        int idx, val;
        public Stone(int idx, int val){
            this.idx = idx;
            this.val = val;
        }
    }
    
    public int solution(int[] stones, int k) {
        
        PriorityQueue<Stone> pq = new PriorityQueue<>((o1, o2)->Integer.compare(o2.val, o1.val));
        
        for(int i = 0; i < k; i++){
            pq.add(new Stone(i, stones[i]));
        }       
        int answer = pq.peek().val;
        int now = k;
        while(now < stones.length){
            pq.add(new Stone(now, stones[now]));
            now++;
            while(pq.peek().idx < now - k){
                pq.poll();
            }
            answer = Math.min(answer, pq.peek().val);
        }
        return answer;
    }
}