import java.util.*;

class Solution {
    public int solution(int[][] targets) {
        Arrays.sort(targets, (a, b) -> a[0] - b[0]);
        int answer = 1, now = targets[0][1];
        for(int i = 1; i < targets.length; i++){
            if(now <= targets[i][0]){
                answer++;
                now = targets[i][1];
            }
            else{
                now = Math.min(now, targets[i][1]);
            }
        }
        return answer;
    }
}