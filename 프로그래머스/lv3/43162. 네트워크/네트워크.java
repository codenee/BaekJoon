class Solution {
    
    private static boolean[] visit;
    private static int[][] computer;
    
    public int solution(int n, int[][] computers) {
        computer = computers;
        visit = new boolean[n];
        int answer = 0;
        for(int i = 0; i < n; i++){
            if(!visit[i]){
                answer++;
                dfs(i);
            }
        }
        
        return answer;
    }
    private static void dfs(int now){
        if(visit[now]){
            return;
        }
        visit[now] = true;
        for(int i = 0; i < computer[now].length; i++){
            if(computer[now][i] == 1){
                dfs(i);
            }
        }
    }
}