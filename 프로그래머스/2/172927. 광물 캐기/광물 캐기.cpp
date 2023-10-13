#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int len = 0, answer = INT16_MAX;
unordered_map<string, int> mineral, hash;
vector<vector<int>> board;
vector<string> vec;

void dfs(vector<int> &picks, int location, int sum){
    int sumList[3] = {0,};
    int point = 0;
    if(len <= location || picks[0] + picks[1] + picks[2] == 0 ){
        answer = min(answer, sum);
        return;
    }
    for(int i = location; i < location + 5; i++){
        if( i >= len){
            point = i;
            break;
        }
        sumList[0] += board[0][mineral[vec[i]]];
        sumList[1] += board[1][mineral[vec[i]]];
        sumList[2] += board[2][mineral[vec[i]]];
        point = i;
    }
    for(int i = 0; i < 3; i++){
        if(picks[i] != 0){
            picks[i] -= 1;
            dfs(picks, point+1, sum+sumList[i]);
            picks[i] += 1;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
       
    board = {
        {1,1,1}, {5,1,1}, {25, 5, 1}
    };
    vec = minerals;
    mineral["diamond"] = 0;
    mineral["iron"] = 1;
    mineral["stone"] = 2;
    
    len = minerals.size();
    
    dfs(picks, 0, 0);
    
    return answer;
}