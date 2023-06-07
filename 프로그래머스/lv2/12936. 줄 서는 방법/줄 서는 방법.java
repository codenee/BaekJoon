import java.util.*;

class Solution {
    public int[] solution(int n, long k) {
        long fact = 1;
        ArrayList<Integer> list = new ArrayList<>();
        for(int i = 1; i <= n; i++){
            list.add(i);
            fact *= i;
        }
        
        k--;
        int idx = 0;
        int[] answer = new int[n];
        for(int i = n; i > 0; i--){
            fact /= i;
            int x = (int)(k / fact);
            k -= fact * x;
            answer[idx++] = list.remove(x);
        }
        return answer;
    }
}