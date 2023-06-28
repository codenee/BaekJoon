import java.util.*;

class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = {};
        
        ArrayList<Integer> arr = new ArrayList<>();
        
        int sum = 0, start = 0, end = 0;
        for(int i = 0; i < sequence.length; i++){
            end = i;
            sum += sequence[i];
            while(k < sum){
                sum -= sequence[start++];
            }
            if(k == sum){
                if(answer.length == 0 || end - start < answer[1] - answer[0]){
                    answer = new int[] {start , end};
                }
            }
        }
        
        return answer;
    }
}