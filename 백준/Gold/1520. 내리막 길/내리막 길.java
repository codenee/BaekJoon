import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static final int[] dist = {1, 0, -1, 0, 1};

    private static int N, M;
    private static int[][] board;
    private static int[][] cnt;

    public static void main(String[] args) throws IOException{
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       StringTokenizer st = new StringTokenizer(br.readLine());
       N = Integer.parseInt(st.nextToken());
       M = Integer.parseInt(st.nextToken());

       board = new int[N][M];
       cnt = new int[N][M];

       for (int i = 0; i < N; i++) {
          st = new StringTokenizer(br.readLine());
          for (int j = 0; j < M; j++) {
            board[i][j] = Integer.parseInt(st.nextToken());
            cnt[i][j] = -1;
          }
       }

       cnt[N-1][M-1] = 1;
       dfs(0, 0);

       System.out.println(cnt[0][0]);
    }

    private static int dfs(int row, int col) {
      if(cnt[row][col] >= 0){
        return cnt[row][col];
      }

      cnt[row][col] = 0;

      for (int i = 0; i < 4; i++) {
        int nr = row + dist[i];
        int nc = col + dist[i+1];
        if(nr < 0 || nc < 0 || nr >= N || nc >= M){
          continue;
        }
        
        if(board[row][col] > board[nr][nc]){
          cnt[row][col] += dfs(nr, nc);
        }
      }
      return cnt[row][col];
    }

}
