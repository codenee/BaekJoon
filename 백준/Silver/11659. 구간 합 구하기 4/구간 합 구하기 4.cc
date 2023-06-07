#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> num(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int input = 0;
		scanf("%d", &input);
		num[i] = num[i-1] + input;
	}

	vector<int> result(m, 0);
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0;
		scanf("%d %d", &start, &end);
		result[i] = num[end] - num[start - 1];
	}

	for (const auto& it : result) {
		printf("%d\n", it);
	}


	return 0;
}