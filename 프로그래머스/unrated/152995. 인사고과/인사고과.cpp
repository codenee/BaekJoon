#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Emp{
    int score;
    int score2;
    int id;
    Emp(int a, int b, int c) : score(a), score2(b), id(c){}
    bool operator<(const Emp& b)const{
        if(score == b.score){
            return score2 > b.score2;
        }
        return score > b.score;
    }
};

int solution(vector<vector<int>> scores) {

    int target = scores[0][0] + scores[0][1];
    vector<Emp> vec;
    for(int i = 0; i < scores.size(); i++){
        if(scores[i][0] > scores[0][0] && scores[i][1] > scores[0][1]){
            return -1;
        }
        vec.push_back(Emp(scores[i][0], scores[i][1], i));
    }

    sort(begin(vec), end(vec));

    map<int, int> hash;
    vector<int> scoreList;

    for(int i = 0; i < vec.size(); i++){
        bool flag = true;
        for(int j = 0; j < i; j++){
            if(vec[j].score > vec[i].score && vec[j].score2 > vec[i].score2){
                flag = false;
                break;
            }
        }
        if(flag == false){
            continue;
        }

        int sum = vec[i].score + vec[i].score2;

        if(!hash.count(sum)){
            scoreList.push_back(sum);
        }
        hash[sum] += 1;
    }

    sort(begin(scoreList), end(scoreList), greater<int>());

    int answer = 1;
    for(int i = 0; i < scoreList.size(); i++){
        if(scoreList[i] == target){
            return answer;
        }
        answer += hash[scoreList[i]];
    }

    return answer;
}
