#include <string>
#include <vector>
#include <map>


using namespace std;

int dist[6] = {1, 0, -1, 0, 1};
map<char, int> m = { {'S',0 }, {'W', 1},{'N',2},{'E', 3} };

bool checkMap(int startx, int endx, int starty, int endy, int index,const vector<string>& park) {
    
	while( (startx != endx) || (starty != endy) ){
        startx += dist[index];
        starty += dist[index+1];
        if(park[startx][starty] == 'X'){
            return false;
        }
    }
	return true;
}


vector<int> solution(vector<string> park, vector<string> routes) {
    
    int x = -1, y = -1;
    for(int i = 0; i < park.size(); i++){
        if(x != -1){
            break;
        }
        for(int j = 0; j < park[0].size(); j++){
            if(y != -1){
                break;
            }
            else if(park[i][j] == 'S'){
                x = i;
                y = j;
                break;
            }
        }
    }    
    vector<int> answer;
    
    for(const auto& it : routes){
        int row = dist[m[it[0]]] * (it[2] - '0');
        int col = dist[m[it[0]]+1] * (it[2] - '0');
        
        if( x + row >= park.size() || y + col >= park[0].size() || x + row < 0 || y + col < 0){
            continue;
        }
        if(park[x+row][y+col] == 'X'){
            continue;
        }
        
   		if (!checkMap(x, x + row, y, y + col, m[it[0]], park)){
		    continue;
	   }
        
        
        x += row;
        y += col;
        
    }
    
    return { x, y };
}