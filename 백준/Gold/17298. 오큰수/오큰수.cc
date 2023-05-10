#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {

	int n = 0;
	scanf("%d", &n);

	vector<int> num(n, 0), answer(n, 0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	stack<int> st;
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && st.top() <= num[i]) {
			st.pop();
		}
		answer[i] = st.empty() ? -1 : st.top();
		st.push(num[i]);
	}

	for (int& it : answer) {
		printf("%d ", it);
	}

	return 0;
}