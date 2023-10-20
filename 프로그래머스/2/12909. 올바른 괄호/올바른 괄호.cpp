#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> st;
    for(const auto& it : s){
        if(it == '('){
            st.push(it);
        }
        else{
            if(st.empty()){
                return false;
            }
            else{
                st.pop();
            }
        }
    }

    return st.empty();
}