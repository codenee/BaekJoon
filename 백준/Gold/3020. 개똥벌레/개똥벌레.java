import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException{
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int H = Integer.parseInt(st.nextToken());

        int len = N > H ? N : H;

        int[] top = new int[len + 1];
        int[] bottom = new int[len + 1];

        for(int i = 0; i < N; i++){
            int a = Integer.parseInt(br.readLine());
            if(i % 2 == 0){
                bottom[a]++;
            }
            else{
                top[ H - a + 1 ]++;
            }
        }

        for(int i = 1; i <= H; i++){
            top[i] += top[i-1];
            bottom[H - i] += bottom[H - i + 1];
        }

        long ans = Long.MAX_VALUE;
        int cnt = 0;
        for(int i = 1; i <= H; i++){
            if(top[i] + bottom[i] < ans){
                cnt = 1;
                ans = top[i] + bottom[i];
            }
            else if(top[i] + bottom[i] == ans){
                cnt++;
            }
        }
        System.out.println(ans + " " + cnt);
    }


}