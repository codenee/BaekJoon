#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board, cnt;
int n, m;

vector<int> dist{ 1, 0, -1, 0, 1 };

int dfs(int row, int col) {
	if (cnt[row][col] >= 0) {
		return cnt[row][col];
	}
	cnt[row][col] = 0;
	
	for (int i = 0; i < 4; i++) {
		int nr = row + dist[i];
		int nc = col + dist[i + 1];

		if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
			continue;
		}

		if (board[row][col] > board[nr][nc]) {
			cnt[row][col] += dfs(nr, nc);
		}
	}
	return cnt[row][col];
}

int main() {

	scanf("%d %d", &n, &m);

	board.resize(n, vector<int>(m, 0));
	cnt.resize(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	cnt[n - 1][m - 1] = 1;

	dfs(0, 0);

	printf("%d", cnt[0][0]);

	return 0;
}