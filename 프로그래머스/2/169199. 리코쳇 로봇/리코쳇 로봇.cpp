#include <string>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int dist[6] = {1,0,-1,0,1};
queue<pair<int, int>> Q;
vector<vector<int>> map;

int bfs(const vector<string>& board){
    
    while(!Q.empty()){
        int row = Q.front().first;
        int col = Q.front().second;
        Q.pop();
        if(board[row][col] == 'G'){
            return map[row][col] - 1;
        }
        
        for(int i = 0; i < 4; i++){
            int nr = row;
            int nc = col;
            while(1){
                nr += dist[i];
                nc += dist[i+1];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m){
                    nr -= dist[i];
                    nc -= dist[i+1];
                    break;
                }
                if(board[nr][nc] == 'D'){
                    nr -= dist[i];
                    nc -= dist[i+1];
                    break;
                }
            }
            if(map[nr][nc] == 0){
                map[nr][nc] = map[row][col] + 1;
                Q.push({nr,nc});
            }
        }
    }
    return -1;
}

int solution(vector<string> board) {
    
    n = board.size();
    m = board[0].size();
    
    map.resize(n, vector<int>(m, 0));
    
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'R'){
                Q.push({i, j});
                map[i][j] = 1;
                answer = bfs(board);
                break;
            }
            if(!Q.empty()){
                break;
            }
        }
    }

    return answer;
}