#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    string strThird("");
    while(n > 0){
        int tmp = n % 3;
        n /= 3;
        strThird += to_string(tmp);
    }
    
    int len = strThird.size() - 1;
    for(int i = 0; i <= len ; i++){
        int tmp = strThird[i] - '0';
        answer += tmp * pow(3 , len - i);
    }
    
    return answer;
}