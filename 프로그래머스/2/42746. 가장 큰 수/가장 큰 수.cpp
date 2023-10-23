#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> temp;
    for(const auto& it : numbers){
        temp.push_back(to_string(it));
    }
    
    sort(temp.begin(), temp.end(), cmp);
    
    if(temp.at(0) == "0")
        return "0";
    
    for(const auto& it : temp){
        answer += it;
    }
    
    return answer;
}