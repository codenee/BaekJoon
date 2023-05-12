#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    
    if(enemy.size() <= k){
        return enemy.size();
    }
    
    int answer = 0;
    priority_queue<int, vector<int> , greater<int>> pq;
    for(int i = 0; i < enemy.size(); i++){
        int e = enemy[i];
        pq.push(e);
        if(pq.size() > k){
            answer += pq.top();
            pq.pop();
        }
        if(answer > n){
            return i;
        }
        
    }
    
    return enemy.size();
}