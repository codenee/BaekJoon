#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    int end = 0;
    for(const auto& it : section)
    {
        if(it > end){
            end = it + m - 1;
            answer++;
        }    
    }    
    
    
    return answer;
}