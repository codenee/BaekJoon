import java.util.*;

class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = new int[] {-1, -1};
        
        int sum = 0, start = 0, end = 0;
        for(int i = 0; i < sequence.length; i++){
            end = i;
            sum += sequence[i];
            while(k < sum){
                sum -= sequence[start++];
            }
            if(k == sum){
                if((answer[0] == -1 && answer[1] == -1) || end - start < answer[1] - answer[0]){
                    answer[0] = start;
                    answer[1] = end;
                }
            }
        }
        
        return answer;
    }
}