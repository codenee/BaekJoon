#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
	vector<string> answer;

	map<int, string> nRank;
	map<string, int> strRank;

	for (int i = 0; i < players.size(); i++) {
		nRank[i] = players[i];
		strRank[players[i]] = i;
	}

	for (int i = 0; i < callings.size(); i++) {
		int cur = strRank[callings[i]];
		string name = nRank[cur - 1];
		nRank[cur - 1] = callings[i];
		nRank[cur] = name;
		strRank[callings[i]] = cur - 1;
		strRank[name] = cur;
	}

	for (const auto& it : nRank) {
		answer.push_back(it.second);
	}
	
	return answer;
}
