#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(vector<string> a, vector<string> b) {
	return a[1] < b[1];
}

vector<string> solution(vector<vector<string>> plans) {
	vector<string> answer;
	
	sort(begin(plans), end(plans), cmp);

	vector<pair<string, int>> vec;
	int time = 0;
	for (const auto& it : plans) {
		int newTime = 60 * (stoi(it[1].substr(0, 2))) + stoi(it[1].substr(3, 5));

		while (time < newTime) {
			if (vec.size() > 0) {
				vec.back().second--;
				if (vec.back().second == 0) {
					answer.push_back(vec.back().first);
					vec.pop_back();
				}
			}
			time++;
		}
		vec.push_back({ it[0], stoi(it[2]) });
	}
	
	while (vec.size() > 0) {
		answer.push_back(vec.back().first);
		vec.pop_back();
	}
	
	return answer;
}
