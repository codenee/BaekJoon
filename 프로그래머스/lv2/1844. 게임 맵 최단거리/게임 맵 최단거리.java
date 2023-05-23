import java.util.*;

class Solution {
    
    private static int[] dist = {1, 0, -1, 0, 1};
    
    private static class Point{
        int x, y;
        public Point(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    
    public int solution(int[][] maps) {
        int answer = 0;
        
        int[][] board = new int[maps.length][maps[0].length];
        ArrayDeque<Point> queue = new ArrayDeque<>();
        
        queue.add(new Point(0, 0));
        
        board[0][0] = 1;
        board[maps.length-1][maps[0].length-1] = -1;
        
        while(!queue.isEmpty()){
            Point now = queue.poll();
            
            for(int i = 0; i < 4; i++){
                int nr = now.x + dist[i];
                int nc = now.y + dist[i+1];
                if(nr < 0 || nc < 0|| nr >= maps.length || nc >= maps[0].length || board[nr][nc] > 0 || maps[nr][nc] == 0){
                    continue;
                }
                queue.add(new Point(nr, nc));
                board[nr][nc] = board[now.x][now.y] + 1;
            }
        }
        
        
        
        return board[maps.length-1][maps[0].length-1];
    }
}