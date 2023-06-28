#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {

   vector<int> answer;
   int start = 0, end = 0, sum = 0;
   for(int i = 0; i < sequence.size(); i++){
        end = i;
        sum += sequence[end];
        while(sum > k){
            sum -= sequence[start++];
        }
        if(sum == k){
            if(answer.empty() || end - start < answer[1] - answer[0]){
                answer = {start, end};
            }
        }
   }
    
    return answer;
}


vector<int> solution2(vector<int> sequence, int k) {
    
    vector<int> answer(2, 0);
    queue<pair<int, int>> q;
    int n = sequence.size(), len = 1000001, sum = 0;
    
    for(int i = 0; i < n; i++){
        q.push({sequence[i], i});
        sum += sequence[i];
        while(sum > k){
            sum -= q.front().first;
            q.pop();
        }
        if(sum == k && q.size() < len){
            len = q.size();
            answer[0] = q.front().second;
            answer[1] = q.back().second;
        }
    }
    
    return answer;
}