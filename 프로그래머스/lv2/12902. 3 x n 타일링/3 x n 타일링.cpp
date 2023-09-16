#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    long long answer = 1;
    if( n % 2 == 1){
        return 0;
    }
    else{
        long long m = 1;
        long long tmp;
        for(int i = 2; i <= n; i += 2){
            tmp = answer;
            answer = ( (answer * 4) % 1'000'000'007 - m % 1'000'000'007 + 1'000'000'007 ) % 1'000'000'007;
            m = tmp;
        }
    }
    
    
    return answer;
}