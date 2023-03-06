#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    map<char, int> hash;
    for(const auto& it : keymap){
        for(int j = 0; j < it.size(); j++){
            if(hash[it[j]] > 0){
                hash[it[j]] = min(hash[it[j]] - 1, j) + 1;
            }
            else{
                hash[it[j]] = j+1;
            }
        }
    }
    
    for(const auto& it : targets){
        int cnt = 0;
        bool check = true;
        for(int j = 0; j < it.size(); j++){
            if(!check){
                continue;
            }
            if(hash[it[j]] < 1){
                check = false;
                cnt = -1;
            }
            else{
                cnt += hash[it[j]];

            }
        }
        answer.push_back(cnt);
    }
    
    return answer;
}