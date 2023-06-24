#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    for(int i = 1 ; i < r2; i++){
        int c1 = 0, c2 = 0;
        c1 = (int)floor(sqrt(pow(r2, 2) - pow(i, 2)));
        if(i < r1){
            c2 = (int)ceil(sqrt(pow(r1, 2) - pow(i, 2)));
        }
        else{
            c2 = 1;
        }
        answer += (c1 - c2 + 1);
    }
    return 4 * (answer + r2 - r1 + 1);
}