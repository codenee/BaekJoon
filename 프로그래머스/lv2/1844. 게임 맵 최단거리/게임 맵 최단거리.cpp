#include<vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> board;
queue<pair<int, int> > Q;

void bfs(const vector<vector<int> > & maps){
    
    vector<int> dist{1, 0, -1, 0, 1};
    
    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dist[i];
            int ny = y + dist[i+1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] > 0 || maps[nx][ny] == 0){
                continue;
            }
            board[nx][ny] += board[x][y] + 1;
            Q.push({nx, ny});
        }
        
    }
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    n = maps.size();
    m = maps[0].size();
    
    board.resize(n + 1, vector<int>(m+1, 0));
    
    Q.push({0,0});
    bfs(maps);
    
    answer = board[n - 1][m - 1];
    if(answer == 0){
        return -1;
    }
    
    return answer + 1;
}