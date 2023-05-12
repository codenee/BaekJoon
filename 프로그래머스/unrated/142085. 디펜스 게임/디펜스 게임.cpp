#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    priority_queue<int> pq;
    
    for(const auto& e : enemy){
        pq.push(e);
        if(k > 0 && n < e){
            n += pq.top();
            pq.pop();
            k--;
        }
        n -= e;
        if(n < 0){
            break;
        }
        answer++;
    }
    
    return answer;
}