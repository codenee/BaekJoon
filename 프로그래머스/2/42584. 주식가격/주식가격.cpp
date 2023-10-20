#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Price{
    int idx, num;
    Price(int a, int b) : idx(a), num(b) {}
};

vector<int> solution(vector<int> prices) {
    
    int len = prices.size();
    vector<int> answer(len, 0);
    stack<Price> st;
    
    for(int i = len - 1; i >= 0; i--){
        while(!st.empty()){
            if(st.top().num >= prices[i]){
                st.pop();
            }
            else{
                break;
            }
        }
        if(st.empty()){
            answer[i] = len - i -1;
        }
        else{
            answer[i] = st.top().idx - i;
        }
        st.push(Price(i, prices[i]));
    }
    
    return answer;
}