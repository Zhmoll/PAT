#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int threshold;
vector<vector<vector<bool>>> matrix; //  L * M * N;
struct xyz {
	int x, y, z;
	xyz(int x, int y, int z) :x(x), y(y), z(z) {};
};
int main() {
	int M; // M and N are the sizes of each slice (i.e. pixels of a slice are in an M by N matrix, and the maximum resolution is 1286 by 128)
	int N;
	int L; // L (<=60) is the number of slices of a brain
	int T; // T is the integer threshold (i.e. if the volume of a connected core is less than T, then that core must not be counted)
	scanf("%d%d%d%d", &M, &N, &L, &T);
	threshold = T;

	matrix.resize(L);
	for (int i = 0; i < L; i++) {
		matrix[i].resize(M);
		for (int j = 0; j < M; j++) {
			matrix[i][j].resize(N);
		}
	}

	int tmp;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				scanf("%d", &tmp);
				matrix[i][j][k] = tmp;
			}
		}
	}

	int count = 0;
	queue<xyz> q;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				int volumn = 0;

				if (matrix[i][j][k]) {
					q.push(xyz(i, j, k));
					matrix[i][j][k] = false;

					while (q.size() != 0) {
						xyz current = q.front();
						volumn++;
						q.pop();
						if (current.x + 1 < L && matrix[current.x + 1][current.y][current.z]) {
							matrix[current.x + 1][current.y][current.z] = false;
							q.push(xyz(current.x + 1, current.y, current.z));
						}
						if (current.x - 1 >= 0 && matrix[current.x - 1][current.y][current.z]) {
							matrix[current.x - 1][current.y][current.z] = false;
							q.push(xyz(current.x - 1, current.y, current.z));
						}
						if (current.y + 1 < M && matrix[current.x][current.y + 1][current.z]) {
							matrix[current.x][current.y + 1][current.z] = false;
							q.push(xyz(current.x, current.y + 1, current.z));
						}
						if (current.y - 1 >= 0 && matrix[current.x][current.y - 1][current.z]) {
							matrix[current.x][current.y - 1][current.z] = false;
							q.push(xyz(current.x, current.y - 1, current.z));
						}
						if (current.z + 1 < N && matrix[current.x][current.y][current.z + 1]) {
							matrix[current.x][current.y][current.z + 1] = false;
							q.push(xyz(current.x, current.y, current.z + 1));
						}
						if (current.z - 1 >= 0 && matrix[current.x][current.y][current.z - 1]) {
							matrix[current.x][current.y][current.z - 1] = false;
							q.push(xyz(current.x, current.y, current.z - 1));
						}
					}
				}

				if (volumn >= threshold) {
					count += volumn;
				}
			}
		}
	}

	printf("%d", count);

	return 0;
}