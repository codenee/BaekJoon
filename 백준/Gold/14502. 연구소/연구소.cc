#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int N, M;
int dist[6] = { 1, 0, -1, 0, 1 };
vector<vector<int>> map;

deque<pair<int, int>> virus;

int bfs(deque<pair<int, int>>& block) {
	vector<vector<int>> map2(map);

	for (const auto& node : block) {
		map2[node.first][node.second] = 1;
	}

	deque<pair<int, int>> Q(virus);
	
	while (!Q.empty()) {
		int row = Q.front().first;
		int col = Q.front().second;
		Q.pop_front();
		for (int i = 0; i < 4; i++) {
			int nr = row + dist[i];
			int nc = col + dist[i + 1];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M) {
				continue;
			}
			if (map2[nr][nc] == 1) {
				continue;
			}
			if (map2[nr][nc] == 0) {
				map2[nr][nc] = 2;
				Q.push_back({ nr, nc });
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map2[i][j] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	scanf("%d %d", &N, &M);

	map.resize(N, vector<int>(M, 0));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}

	deque<pair<int, int>> block;

	int answer = 0;
	for (int i = 0; i < N * M - 2; i++) {
		if (map[i / M][i % M] != 0) {
			continue;
		}
		block.push_back({ i / M, i%M });
		for (int j = i + 1; j < N * M - 1; j++) {
			if (map[j / M][j % M] != 0) {
				continue;
			}
			block.push_back({ j / M, j % M });
			for (int k = j + 1; k < N * M; k++) {
				if (map[k / M][k % M] != 0) {
					continue;
				}
				block.push_back({ k / M, k % M });
				answer = max(answer, bfs(block));
				block.pop_back();
			}
			block.pop_back();
		}
		block.pop_back();
	}

	printf("%d", answer);

	return 0;
}