#include <algorithm>
#include <vector>
#include <stdio.h>
#include <climits>


using namespace std;

int main(){

    int n = 0, h = 0;
    scanf("%d %d", &n, &h);

     int top[500001] = {0,};
    int bottom[500001] = {0,};
    int input = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &input);
        if(i % 2 == 0){
            bottom[input]++;
        }
        else{
            top[h - input + 1]++;
        }
    }

    for(int i = 1; i <= h; i++){
        top[i] += top[i-1];
        bottom[h - i] += bottom[h - i + 1];
    }

    long long ans = LONG_LONG_MAX;
    int cnt = 0;
    for(int i = 1; i <= h; i++){
        if(top[i] + bottom[i] < ans){
            cnt = 1;
            ans = top[i] + bottom[i];
        }
        else if(top[i] + bottom[i] == ans){
            cnt++;
        }
    }
   
   printf("%d %d", ans, cnt);

    return 0;
}
