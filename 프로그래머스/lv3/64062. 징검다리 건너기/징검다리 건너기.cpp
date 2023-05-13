#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> stones, int k) {
    
    priority_queue<pair<int, int>> pq;
    int i;
    for(i = 0; i < k; i++){
        pq.push({stones[i], i});
    }
    
    int answer = pq.top().first;
    while(i < stones.size()){
        pq.push({stones[i], i});
        i++;
        while(pq.top().second < i - k){
            pq.pop();
        }
        answer = min(answer, pq.top().first);
    }
    
    return answer;
}