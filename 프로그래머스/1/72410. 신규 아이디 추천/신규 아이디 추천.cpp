#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    
    for(char c : new_id){
        if( (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') ||  c == '-' || c == '_' || c == '.'){
              answer += c;
        }
    }
    
    string tmp("");
    for(int i = 0; i < answer.size(); i++){
        if(answer[i] == '.'){
            int cnt = 0;
            for(int j = i+1; j < answer.size(); j++){
                if(answer[j] == '.')   
                    cnt++;
                else    
                    break;
            }    
            if(cnt > 0){
                tmp += '.';
                i += cnt;
            }
            else
                tmp += answer[i];
            }
        else{
            tmp += answer[i];
        }

    }
    
    if(tmp.front() == '.')
        tmp.erase(tmp.begin());
    
    if(tmp.back() == '.')
        tmp.pop_back();
    
    if(tmp.empty())
        tmp = "a";
    
    if(tmp.size() >= 16)
        tmp = tmp.substr(0, 15);
    
    if(tmp.back() == '.')
        tmp.pop_back();
    
    while(tmp.size() <= 2){
        tmp.push_back(tmp.back());
    }
    
    answer = tmp;
    
    
    return answer;
}