#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int len = s.size();
    s += s;
    
    map<char, char> hash;
    hash['('] = ')';
    hash['['] = ']';
    hash['{'] = '}';
    
    for(int i = 0; i < len; i++){
        string str = s.substr(i, len);
        stack<char> st;
        bool check = false;
        for(const auto& it : str){
            if(it == '(' || it == '{' || it == '['){
                st.push(it);
            }
            else{
                if(st.empty()){
                    check = false;
                    break;
                }
                else{
                    if(hash[st.top()] == it){
                        st.pop();
                        check = true;
                    }
                    else{
                        check = false;
                        break;
                    }
                }
            }
        }
        if(st.empty() && check){
            answer++;
        }
    }
    
    return answer;
}