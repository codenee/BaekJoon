import java.util.*;
class Solution {
    public int solution(int n, int k, int[] enemy) {
        int answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());     
        for(int e : enemy){
            pq.add(e);
            if(k > 0 && n < e){
                n += pq.poll();
                k--;
            }
            n -= e;
            if(n < 0){
                break;
            }
            answer++;
        }
        
        return answer;
    }
}