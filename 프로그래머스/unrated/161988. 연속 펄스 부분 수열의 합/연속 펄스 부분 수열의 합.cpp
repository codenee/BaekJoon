#include <string>
#include <vector>
#include <climits>

using namespace std;

long long lmax(long long a, long long b){
    if(a < b)
        return b;
    return a;
}

long long solution(vector<int> sequence) {

    vector<int> arr;
    for(int i = 0; i < sequence.size(); i++){
        int num = sequence[i];
        if(i % 2 == 1){
            num *= -1;
        }
        arr.push_back(num);
    }
    
    long long answer = LLONG_MIN;
    long long psum = 0;
    
    for(int i = 0; i < arr.size(); i++){
        psum = lmax(psum, 0) + arr[i];
        answer = lmax(answer , psum);
    }
    
    psum = 0;
    for(int i = 0; i < arr.size(); i++){
        psum = lmax(psum, 0) - arr[i];
        answer = lmax(answer , psum);
    }
    
    return answer;
}