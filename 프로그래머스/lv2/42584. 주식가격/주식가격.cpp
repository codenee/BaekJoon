#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
   
    int len = prices.size();
    vector<int> answer(len, 0);
    stack<pair<int,int>> st;
    
    for(int i = len - 1; i >= 0; i--){
        while(!st.empty()){
            if(st.top().second >= prices[i]){
                st.pop();
            }
            else{
                break;
            }
        }
        if(st.empty()){
            answer[i] = len - i - 1;
        }
        else{
            answer[i] = st.top().first - i;
        }
        st.push(make_pair(i, prices[i]));
    }
    
    
    return answer;
}