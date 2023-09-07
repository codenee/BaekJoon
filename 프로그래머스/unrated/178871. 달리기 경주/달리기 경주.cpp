#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
	vector<string> answer;

	map<string, int> mRank;

	for (int i = 0; i < players.size(); i++) {
		mRank[players[i]] = i;
	}

	int n1 = 0, n2 = 0;
	string tmp;
	for (int i = 0; i < callings.size(); i++) {
		n2 = mRank[callings[i]];
		n1 = n2 - 1;
		mRank[players[n2]]--;
		mRank[players[n1]]++;
		tmp = players[n2];
		players[n2] = players[n1];
		players[n1] = tmp;
	}

	answer = players;
	
	return answer;
}