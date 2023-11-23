#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec(9, 0);
bool check[10] = { 0, };
vector<int> result;

void DFS(int len ,int s) {
	if (len == 7) {
		int sum = 0;
		vector<int> tmp;
		for (int i = 0; i < 9; i++) {
			if (check[i]) {
				sum += vec[i];
				tmp.push_back(vec[i]);
			}
		}
		if (sum == 100) {
			result = tmp;
			return;
		}
	}
	else {
		for (int i = s; i < 9; i++) {
			check[i] = true;
			DFS(len + 1, i + 1);
			check[i] = false;
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		scanf("%d", &vec[i]);
	}

	DFS(0, 0);

	for (const auto& it : result) {
		cout << it << "\n";
	}

	return 0;

}