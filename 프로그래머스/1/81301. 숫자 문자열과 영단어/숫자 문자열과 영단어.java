import java.util.concurrent.ConcurrentHashMap;

class Solution {
   private int str2int(String str){
        ConcurrentHashMap<String, Integer> hashMap = new ConcurrentHashMap<>();
        hashMap.put("zero", 0 );
        hashMap.put("one", 1);
        hashMap.put("two", 2);
        hashMap.put("three", 3);
        hashMap.put("four", 4);
        hashMap.put("five", 5);
        hashMap.put("six", 6);
        hashMap.put("seven", 7);
        hashMap.put("eight",8);
        hashMap.put("nine", 9);

        //get value
        Integer num = hashMap.get(str);
        if(num == null){
            return -1;
        }

        return num.intValue();


    }
    public int solution(String s) {



        int answer = 0;
        StringBuilder builder = new StringBuilder();
        StringBuilder tmp = new StringBuilder();
        for(char c : s.toCharArray()){
            if(!Character.isAlphabetic(c)){
                builder.append(c);
            }
            else{
                tmp.append(c);
                int result = str2int(tmp.toString());
                if(result != -1){
                    builder.append(result);
                    tmp.setLength(0);
                }

            }
        }
        answer = Integer.parseInt(builder.toString());

        return answer;
    }

}