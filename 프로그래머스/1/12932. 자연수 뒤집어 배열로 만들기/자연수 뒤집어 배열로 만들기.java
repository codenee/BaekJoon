class Solution {
    
    public int[] solution2(long n){
        String str = Long.toString(n);
        int nLength = str.length();

        int[] answer = new int[nLength];
        for (int i = 0; i < nLength; i++) {
            answer[i] = ( str.charAt(nLength - i - 1) - '0');
        }
        return answer;
    }
    
    public int[] solution3(long n) {
        
      String str = Long.toString(n);
        String reversed = new StringBuilder(str).reverse().toString();
        char[] arr = reversed.toCharArray();
        
        int[] answer = new int[arr.length];
        for(int i = 0; i < answer.length; i++){
            answer[i] = arr[i] - '0';
        }
        return answer;
    }
    public int[] solution(long n){
        String str = Long.toString(n);
        String reversed = new StringBuilder(str).reverse().toString();
        int[] answer = new int[reversed.length()];
        int index = 0;
        for(char c : reversed.toCharArray()){
            answer[index++] = c - '0';
        }
        return answer;
    }
}