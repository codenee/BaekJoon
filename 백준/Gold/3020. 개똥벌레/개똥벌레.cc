#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, H;

    scanf("%d %d", &N, &H);

    vector<int> top(H+1, 0), bottom(H+1, 0);
    for(int i = 0; i < N; i++){
        int input = 0;
        scanf("%d", &input);
        if(i % 2 == 0){
            bottom[input]++;
        }
        else{
            top[H-input+1]++;
        }
    }

    for(int i = 1; i <= H; i++){
        top[i] += top[i-1];
        bottom[H-i] += bottom[H-i+1];
    }

    long long answer = INT32_MAX;
    int cnt = 0;
    for(int i = 1; i <= H; i++){
        if(top[i] + bottom[i] < answer){
            answer = top[i] + bottom[i];
            cnt = 1;
        }
        else if(top[i] + bottom[i] == answer){
            cnt++;
        }
    }
    printf("%lld %d", answer, cnt);
    return 0;
}
