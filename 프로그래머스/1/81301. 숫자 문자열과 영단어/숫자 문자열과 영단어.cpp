#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string EngConvert(string str){
    
    if(str == "zero"){
        return "0";
    }
    else if(str == "one"){
        return "1";
    }
    else if(str == "two"){
        return "2";
    }
    else if(str == "three"){
        return "3";
    }
    else if(str == "four"){
        return "4";
    }
    else if(str == "five"){
        return "5";
    }
    else if(str == "six"){
        return "6";
    }
    else if(str == "seven"){
        return "7";
    }
    else if(str == "eight"){
        return "8";
    }
    else if(str == "nine"){
        return "9";
    }
    
    return "";    
}

int solution(string s) {
    int answer = 0;
    
    string str(""), tmp("");
    for(char c : s){
        if(isalpha(c)){
            tmp += c;
            string eng = EngConvert(tmp);
            if( eng == "")
                continue;
            else{
                str += eng; 
                tmp.clear();
            }
            
        }else{
            str += c;
        }
    }
    
    for(char c : str){
        answer = (10 * answer + (c - 48));
    }
    
    return answer;
}