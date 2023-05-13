#include <string>
#include <vector>

using namespace std;

void dfs(int idx, const vector<vector<int>>& computers, vector<bool> &check){
    
    for(int i = 0; i < computers.size(); i++){
        if(computers[idx][i] == 1 && !check[i]){
            check[i] = true;
            dfs(i,computers, check);
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    
    int answer = 0;
    vector<bool> check(n, false);
    for(int i = 0; i < n; i++){
        if(!check[i]){
            check[i] = true;
            dfs(i,computers, check);
            answer++;
        }
    }
    
    
    return answer;
}