import java.util.ArrayDeque;

class Solution {
    public int[][] solution(int[][] rc, String[] operations) {
        int[][] answer = new int[rc.length][rc[0].length];
        
        ArrayDeque<Integer> left = new ArrayDeque<>();
        ArrayDeque<Integer> right = new ArrayDeque<>();
        ArrayDeque<ArrayDeque<Integer>> mid = new ArrayDeque<>();
        
        for(int[] a : rc){
            ArrayDeque<Integer> row = new ArrayDeque<>();
            for(int j = 0; j < a.length; j++){
                if(j == 0){
                    left.add(a[j]);
                }
                else if(j == a.length - 1){
                    right.add(a[j]);
                }
                else{
                    row.add(a[j]);
                }
            }
            mid.add(row);
        }
        
        for(String operation : operations){
            if("ShiftRow".equals(operation)){
                left.addFirst(left.pollLast());
                mid.addFirst(mid.pollLast());
                right.addFirst(right.pollLast());
            }
            else{
                mid.peekFirst().addFirst(left.pollFirst());
                right.addFirst(mid.peekFirst().pollLast());
                mid.peekLast().addLast(right.pollLast());
                left.addLast(mid.peekLast().pollFirst());
            }
        }
        
        for(int i = 0; i < rc.length; i++){
            int j = 0;
            answer[i][j++] = left.pollFirst();
            ArrayDeque<Integer> row = mid.pollFirst();
            while(!row.isEmpty()){
                answer[i][j++] = row.pollFirst();
            }
            answer[i][j] = right.pollFirst();
        }
        
        return answer;
    }
}