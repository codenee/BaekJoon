#include <string>
#include <vector>

using namespace std;

static int answer = 50;

void dfs(string begin, const string target, const vector<string>& words, vector<bool> check, int count = 0){
    if(begin == target){
        if(answer > count){
            answer = count;
            return;
        }
    }
    
    for(int i = 0; i < words.size(); i++){
        if(check[i])
            continue;
        
        int b_cnt = 0;
        for(int j = 0; j < words[i].length(); j++){
            if(begin[j] != words[i][j])
                b_cnt++;
        }
        
        if(b_cnt == 1){
            check[i] = true;
            dfs(words[i], target, words, check, count +1);
            check[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {

    vector<bool> check(words.size(), false);
    dfs(begin, target, words, check);   
    return answer == 50 ? 0 : answer;
}