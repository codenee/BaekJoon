#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {

	deque<int> left, right;
	deque<deque<int>> mid;

	int row = rc.size(), col = rc[0].size();
	for (int i = 0; i < row; i++) {
		left.emplace_back(rc[i][0]);
		right.emplace_back(rc[i][col - 1]);
		deque<int> dq;
		for (int j = 1; j < col - 1; j++) {
			dq.emplace_back(rc[i][j]);
		}
		mid.emplace_back(dq);
	}

	for (const auto& oper : operations) {
		if (oper == "ShiftRow") {
			
			left.push_front(std::move(left.back()));
			left.pop_back();

			right.push_front(std::move(right.back()));
			right.pop_back();

			mid.emplace_front(std::move(mid.back()));
			mid.pop_back();
			

		}
		else {
			
			mid[0].emplace_front(std::move(left.front()));
			left.pop_front();

			right.push_front(std::move(mid[0].back()));
			mid[0].pop_back();

			mid[row - 1].emplace_back(std::move(right.back()));
			right.pop_back();

			left.push_back(std::move(mid[row-1].front()));
			mid[row - 1].pop_front();

		}
	}

	vector<vector<int>> answer(row, vector<int>(col, 0));
	for (int i = 0; i < row; i++) {
		answer[i][0] = left[i];
		answer[i][col - 1] = right[i];
		for (int j = 1; j < col - 1; j++) {
			answer[i][j] = mid[i].front();
			mid[i].pop_front();

		}
	}

	return answer;
}