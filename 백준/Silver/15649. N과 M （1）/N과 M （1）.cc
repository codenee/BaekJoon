#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template <typename S> void println(const S& s) {

	for (const auto& p : s) {
		cout << p << "\n";
	}
}

int N, M;
vector<string> vec;
vector<bool> used;

void backtrack(int len, string ans) {
	if (len == M) {
		string str = ans.substr(1);
		vec.push_back(str);
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!used[i]) {
			used[i] = true;
			backtrack(len + 1, ans + " " + to_string(i));
			used[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	used.resize(N + 1, false);

	backtrack(0, "");

	println(vec);

	return 0;
}