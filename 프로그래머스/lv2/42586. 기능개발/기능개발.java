import java.util.*;
class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        
        Stack<Integer> stack = new Stack<Integer>();
        
        int distri = progresses.length;
        for(int i = distri -1; i >= 0; i--)
        {
            stack.add( (100-progresses[i])/speeds[i] + ( (100-progresses[i])%speeds[i] > 0 ? 1 : 0) );
        }
        
        List<Integer> a = new ArrayList<Integer>();
        
        while(!stack.isEmpty())
        {
            int cnt = 1; 
            int top = stack.pop();
            
            while(!stack.isEmpty() && top >= stack.peek())
            {
                cnt++;
                stack.pop();
            }
            a.add(cnt);
        }
        
        int[] answer = new int[a.size()];
        
        for(int i = 0; i < answer.length; i++)
        {
            answer[i] = a.get(i);
        }
        
        return answer;
    }
}