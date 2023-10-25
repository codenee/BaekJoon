#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void myParser(const string& str, vector<string> &result){
    string s = str;
    int pos = 0;
    string token("");
    while( (pos = s.find(" ")) != string::npos){
        token = s.substr(0, pos);
        result.push_back(token);
        s.erase(0, pos + 1);
    }
    result.push_back(s);
}

vector<string> solution(vector<string> record) {
    
    unordered_map<string, string> table;
    vector<pair<string, string>> vec;
    
    for(const auto& rec : record){
        vector<string> value;
        myParser(rec, value);
            if( value[0][0] == 'E'){
                table[value[1]] = value[2]; 
                vec.push_back({"E", value[1]});
            }
            else if(value[0][0] == 'L'){
                vec.push_back({"L", value[1]});
            }
            else if(value[0][0] == 'C'){
                table[value[1]] = value[2];
            }
        
    }
    
    vector<string> answer;
    for(const auto& it : vec){
        string s("");
        if(it.first == "E"){
            s = table[it.second]+"님이 들어왔습니다." ;
            answer.push_back(s);
        }
        else if(it.first == "L"){
            s = table[it.second]+"님이 나갔습니다.";
            answer.push_back(s);
        }
    }
    return answer;
}