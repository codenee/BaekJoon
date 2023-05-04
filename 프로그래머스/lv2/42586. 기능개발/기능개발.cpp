#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    stack<int> nStack;
    
    int distri = progresses.size();
    for(int i = distri-1; i >= 0; i--)
    {
        nStack.push( (100-progresses[i])/speeds[i] + ( (100-progresses[i])%speeds[i] > 0 ? 1 : 0) );
    }
   
    vector<int> answer;

    while(!nStack.empty())
    {
        int cnt = 1;
        int top = nStack.top();
        nStack.pop();
        while(!nStack.empty() && top >= nStack.top())
        {
            cnt++;
            nStack.pop();
        }
        answer.push_back(cnt);
    }
    
    return answer;
}