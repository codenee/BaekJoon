import java.util.*;

class Solution {
    public int[] solution(int n, long k) {
        
        ArrayList<Integer> list = new ArrayList<>();
        long fact = 1;
        for(int i = 1; i <= n; i++){
            fact *= i;
            list.add(i);
        }
        
        int[] answer = new int[n];
        k--;
        int idx = 0;
        for(int i = n; i > 0; i--){
            fact /= i;
            int x = (int)(k / fact);
            k -= fact * x;
            answer[idx++] = list.remove(x);
        }
        return answer;
    }
}