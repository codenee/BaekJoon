import java.util.*;

class Solution {
    boolean solution(String s) {
        boolean answer = true;
        
        ArrayDeque<Character> stack = new ArrayDeque<>();
        for(int i = 0; i < s.length(); i++){
            char now = s.charAt(i);
            if(now == '('){
                stack.addLast(now);
            }
            else{
                if(stack.isEmpty()){
                    return false;
                }
                else{
                    stack.pollLast();
                }
            }
        }

        return stack.isEmpty();
    }
}