#include <cstdio>
#include <vector>
#define INF 1000000000
using namespace std;

int Adj[205][205];
int N;

void Flyod() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (Adj[i][k] != INF && Adj[k][j] != INF && Adj[i][j] > Adj[i][k] + Adj[k][j]) {
					Adj[i][j] = Adj[i][k] + Adj[k][j]
				}
			}
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);
	fill(Adj, Adj + N * N, INF);
	for (int i = 0; i < N; i++) {
		Adj[i][i] = 0;
	}
	// 输入
	return 0;
}