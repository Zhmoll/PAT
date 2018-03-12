#include <cstdio>
#include <vector>
#define INF 1000000000
using namespace std;

struct Node {
	int v;
	int dis;
};

vector<vector<int>> d;
int N, M;

void Floyd() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (d[i][k] != INF && d[k][j] != INF && d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
}

int main() {
	return 0;
}