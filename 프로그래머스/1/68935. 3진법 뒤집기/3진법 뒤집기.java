class Solution {
    public int solution(int n) {
          int answer = 0;
        
        StringBuilder builder = new StringBuilder();
        
        int num = n;
        while(num > 0){
            builder.append( (num % 3) );
            num = num / 3;
            
        }
        
        String str = builder.toString();
        int index = str.length() - 1;
        for(char c : str.toCharArray()){
            answer += ( (c - '0') * (int) Math.pow(3, index--) );
        }        
        return answer;
    }
}