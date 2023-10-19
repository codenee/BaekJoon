#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    deque<string> dq;
    for(string& city : cities){
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        
        bool hit = false;
        int index = 0;
        for(index = 0; index < dq.size(); index++){
            if(dq[index] == city){
                hit = true;
                break;
            }
        }
        
        dq.push_back(city);
        if(hit){
            answer += 1;
            dq.erase(dq.begin() + index);
        }
        else{
            answer += 5;
            if(dq.size() > cacheSize){
                dq.pop_front();
            }
        }
        
    }
    
    return answer;
}