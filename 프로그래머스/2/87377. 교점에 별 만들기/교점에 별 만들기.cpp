#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    
    long long minX = LLONG_MAX, minY = LLONG_MAX;
    long long maxX = LLONG_MIN, maxY = LLONG_MIN;
    
    int lineSize = line.size();
    vector<pair<long long, long long>> coords;
    
    for(int i = 0; i < lineSize; i++){
        for(int j = i+1; j < lineSize; j++){
            
            long long A = line[i][0], B = line[i][1], E = line[i][2];
            long long C = line[j][0], D = line[j][1], F = line[j][2];
            
            long long xNumberator = B * F * 1LL - E * D * 1LL;
            long long yNumberator = E * C * 1LL - A * F * 1LL;
            
            long long mod = A * D * 1LL - B * C * 1LL;
            
            if(mod == 0){
                continue;
            }
            
            if(xNumberator % mod || yNumberator % mod){
                continue;
            }
            
            long long x = xNumberator / mod;
            long long y = yNumberator / mod;
            
            minX = min(minX, x);
            minY = min(minY, y);
            maxX = max(maxX, x);
            maxY = max(maxY, y);
            
            coords.push_back({x, y});
        }
    }
    
    string row = string(maxX - minX + 1, '.');   
    vector<string> answer(maxY - minY + 1, row);
    
    for(auto &it : coords){
        answer[abs(it.second - maxY)][abs(it.first - minX)] = '*';
    }
    
    return answer;
}