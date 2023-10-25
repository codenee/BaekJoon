#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void myParser(const string& str, vector<string>& value){
    string s = str, token("");
    int pos = 0;
    while( (pos = s.find(" ")) != string::npos ){
        token = s.substr(0, pos);
        value.push_back(token);
        s.erase(0, pos + 1);
    }
    value.push_back(s);
}

vector<string> solution(vector<string> record) {
    
    unordered_map<string, string> msg;
    unordered_map<string, string> nickname;
    vector<pair<string, string>> vec;
    
    msg["Enter"] = "님이 들어왔습니다.";
    msg["Leave"] = "님이 나갔습니다.";
    
    for(string& s : record){
        vector<string> value;
        myParser(s, value);
        if(value.size() == 3){
            nickname[value[1]] = value[2];
        }
        if(value[0][0] == 'E'){
            vec.push_back({value[0], value[1]});
        }
        else if(value[0][0] == 'L'){
            vec.push_back({value[0], value[1]});
        }
    }    
    
    vector<string> answer;
    for(const auto& it : vec){
        string str = nickname[it.second] + msg[it.first];
        answer.push_back(str);
    }
    return answer;
}