class Solution {
   boolean solution(String s) {
        boolean answer = true;  
        
        s = s.toLowerCase();

       int ps = s.length() - s.replace("p", "").length();
       int ys = s.length() - s.replace("y", "").length();

        return ps == ys;
    }

}