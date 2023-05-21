#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int n, m;
int dist[6] = {1, 0, -1, 0, 1};

vector<vector<int>> board;
vector<vector<int>> cnt;

int dfs(int row, int col){
    if(cnt[row][col] >= 0){
        return cnt[row][col];
    }
    cnt[row][col] = 0;
    for(int i = 0; i < 4; i++){
        int nr = row + dist[i];
        int nc = col + dist[i+1];

        if(nr < 0 || nc < 0 || nr >= n || nc >= m){
            continue;
        }

        if(board[row][col] > board[nr][nc]){
            cnt[row][col] += dfs(nr, nc);
        }

    }
    return cnt[row][col];
}

int main(){

	//freopen("E:/vscode/inflearn/ex2/input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    board.resize(n, vector<int>(m,0));
    cnt.resize(n, vector<int>(m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &board[i][j]);
            cnt[i][j] = -1;
        }
    }

    cnt[n-1][m-1] = 1;

    dfs(0, 0);

    printf("%d\n", cnt[0][0]);


    return 0;
}
