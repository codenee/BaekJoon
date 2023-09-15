#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    
    vector<vector<int>> graph(n+1);
    for(const auto& road : roads){
        graph[road[0]].push_back(road[1]);
        graph[road[1]].push_back(road[0]);
    }
    
    vector<int> answer(sources.size(), 0);
    vector<int> dest(n+1, -1);
    dest[destination] = 0;
    queue<pair<int, int>> Q;
    Q.push({destination, 0});
    
    while(!Q.empty()){
        int curPos = Q.front().first;
        int curCnt = Q.front().second;
        Q.pop();
        for(int i = 0; i < graph[curPos].size(); i++){
            int nextPos = graph[curPos][i];
            if(dest[nextPos] == -1 || dest[nextPos] > curCnt + 1){
                Q.push({nextPos, curCnt + 1});
                dest[nextPos] = curCnt + 1;
            }
        }
    }
    
    for(int i = 0; i < sources.size(); i++){
        answer[i] = dest[sources[i]];
    }
    
    return answer;
}