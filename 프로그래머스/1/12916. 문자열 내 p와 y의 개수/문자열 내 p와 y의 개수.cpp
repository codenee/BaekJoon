#include <string>
#include <iostream>
#include <map>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    map<char, int> hash;
    for(const auto &it : s){
        if(it == 'P'){
            hash['p'] += 1;
        }
        else if(it == 'Y'){
            hash['y'] += 1;
        }
        else{
            hash[it] += 1;
        }
    }
        
    return hash['p'] == hash['y'] ? true : false;
}