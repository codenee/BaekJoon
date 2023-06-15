import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

/**
 * Main
 */
public class Main {

    private static int N, M;
    private static boolean[] used;
    private static StringBuilder sb;

    public static void main(String[] args) throws IOException{
        //System.setIn(new FileInputStream("input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        used = new boolean[N+1];
        sb = new StringBuilder();

        backtrack(0, "");

        System.out.println(sb);

    }

    private static void backtrack(int len, String s) {
        if(len == M){
            sb.append(s.trim()).append("\n");
        }

        for (int i = 1; i <= N; i++) {
            if(!used[i]){
                used[i] = true;
                backtrack(len+1, s+" "+i);
                used[i] = false;
            }
        }
    }

    
}