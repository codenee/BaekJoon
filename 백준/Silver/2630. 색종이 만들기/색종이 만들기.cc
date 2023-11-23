#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board;
int white, blue;

void DivideSqure(int x, int y, int n) {

	int cnt = 0;
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (board[i][j]) {
				cnt++;
			}
		}
	}
	if (cnt == 0) {
		white++;
	}
	else if (cnt == n * n) {
		blue++;
	}
	else {
		DivideSqure(x, y, n / 2);
		DivideSqure(x + n / 2, y, n / 2);
		DivideSqure(x, y + n / 2, n / 2);
		DivideSqure(x + n / 2, y + n / 2, n / 2);
	}

	return;
}

int main() {

	int n = 0;
	scanf("%d", &n);

	board.resize(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	DivideSqure(0, 0, n);
	printf("%d\n%d", white, blue);

	return 0;

}