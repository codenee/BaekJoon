#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;


int main() {

	int n = 0, m = 0;
	scanf("%d %d", &n, &m);

	vector<int> vec(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int value = 0;
		scanf("%d", &value);
		vec[i] = vec[i - 1] + value;
	}

	int a = 0, b = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", vec[b] - vec[a - 1]);
	}
	return 0;
}