class Solution {
    public int[] solution(String s) {
        StringBuilder builder = new StringBuilder();

        int[] answer = new int[2];
        String str = new String(s);
        while(!str.equals("1")){
            int cnt = 0;
            for(char c : str.toCharArray()){
                if(c == '0'){
                    cnt++;
                }
                else{
                    builder.append(c);
                }
            }

            int num = builder.length();
            str = Integer.toString(num, 2);
            builder.setLength(0);

            answer[0]++;
            answer[1] += cnt;
        }
        return answer;
    }
}