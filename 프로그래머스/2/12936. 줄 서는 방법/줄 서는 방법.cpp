#include <string>
#include <vector>

using namespace std;
vector<int> solution(int n, long long k) {

	long long fact = 1;
	vector<int> list;
	for (int i = 1; i <= n; i++) {
		fact *= i;
		list.push_back(i);
	}

	k--;

	vector<int> answer(n, 0);
	int idx = 0;
	for (int i = n; i > 0; i--) {
		fact /= i;
		int x = (int)(k / fact);
		k -= fact * x;
		answer[idx++] = list[x];
		list.erase(list.begin()+x);
	}

	return answer;
}