#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);

	int m, n;
	for (m = 1; m <= N; m++) {
		for (n = 1; n <= m; n++) {
			if (m*n == N)goto out;
		}
	}
out:
	vector<int> input(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);
	}
	sort(input.begin(), input.end(), greater<int>());

	vector<vector<int>>  matrix(m);
	for (int i = 0; i < m; i++) {
		matrix[i].resize(n);
		fill(matrix[i].begin(), matrix[i].end(), -1);
	}

	bool up = false, down = false, left = false, right = true;
	int px = 0, py = 0;
	for (int i = 0; i < N; i++) {
		int tmp = input[i];
		matrix[px][py] = tmp;
		if (right) {
			py++;
			if (py == n || matrix[px][py] != -1) {
				right = false;
				down = true;
				py--;
				px++;
			}
		}
		else if (down) {
			px++;
			if (px == m || matrix[px][py] != -1) {
				down = false;
				left = true;
				px--;
				py--;
			}
		}
		else if (left) {
			py--;
			if (py < 0 || matrix[px][py] != -1) {
				left = false;
				up = true;
				py++;
				px--;
			}
		}
		else if (up) {
			px--;
			if (px < 0 || matrix[px][py] != -1) {
				up = false;
				right = true;
				px++;
				py++;
			}
		}
	}
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			printf("%d", matrix[i][j]);
			if (j != matrix[i].size() - 1) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}