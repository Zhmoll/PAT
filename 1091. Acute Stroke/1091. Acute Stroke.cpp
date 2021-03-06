// 18点53分
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct node {
	int i, j, k;
};

int directioni[6] = { 1,-1,0,0,0,0 };
int directionj[6] = { 0,0,1,-1,0,0 };
int directionk[6] = { 0,0,0,0,1,-1 };

vector<vector<vector<bool>>> matrix;
vector<vector<vector<bool>>> inq;
int M, N, L, T;
bool judge(node d) {
	if (d.i < 0 || d.i == L || d.j < 0 || d.j == M || d.k < 0 || d.k == N)
		return false;
	if (!matrix[d.i][d.j][d.k])
		return false;
	if (inq[d.i][d.j][d.k])
		return false;
	return true;
}

int main() {
	int tmp;
	scanf("%d%d%d%d", &M, &N, &L, &T);
	matrix.resize(L);
	inq.resize(L);
	for (int i = 0; i < L; i++) {
		matrix[i].resize(M);
		inq[i].resize(M);
		for (int j = 0; j < M; j++) {
			matrix[i][j].resize(N);
			inq[i][j].resize(N, false);
			for (int k = 0; k < N; k++) {
				scanf("%d", &tmp);
				matrix[i][j][k] = tmp == 1;
			}
		}
	}

	int total = 0;
	queue<node> q;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (!inq[i][j][k] && matrix[i][j][k]) {
					node tmp = { i,j,k };
					q.push(tmp);
					inq[i][j][k] = true;
					int count = 0;
					while (!q.empty()) {
						node current = q.front();
						count++;
						q.pop();
						for (int l = 0; l < 6; l++) {
							tmp.i = current.i + directioni[l];
							tmp.j = current.j + directionj[l];
							tmp.k = current.k + directionk[l];
							if (judge(tmp)) {
								inq[tmp.i][tmp.j][tmp.k] = true;
								q.push(tmp);
							}
						}
					}
					if (count >= T) total += count;
				}
			}
		}
	}
	printf("%d", total);
	return 0;
}