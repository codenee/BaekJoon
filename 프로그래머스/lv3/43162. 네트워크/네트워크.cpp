#include <string>
#include <vector>

using namespace std;

vector<bool> check;

void dfs(int now, const vector<vector<int>> computers){
    if(check[now]){
        return;
    }
    check[now] = true;
    for(int i = 0; i < computers[now].size(); i++){
        if(computers[now][i] == 1){
            dfs(i, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    check.resize(n);
    
    for(int i = 0; i < n; i++){
        if(!check[i]){
            answer++;
            dfs(i, computers);
        }
    }
    
    return answer;
}