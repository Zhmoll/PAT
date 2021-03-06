#include <cstdio>
#include <cmath>
#include <vector>
#define INF 1000000000
using namespace std;
vector<vector<int>> Adj;

int opt = INF;
int opt_count = 0;

void DFS(int current, int level) {
	if (Adj[current].size() == 0) {
		if (level < opt) {
			opt = level;
			opt_count = 1;
		}
		else if (level == opt) {
			opt_count++;
		}
		return;
	}

	for (int i = 0; i < Adj[current].size(); i++) {
		DFS(Adj[current][i], level + 1);
	}
}

int main() {
	int N;
	double P, r;
	scanf("%d%lf%lf", &N, &P, &r);
	Adj.resize(N);
	int K, tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &K);
		for (int j = 0; j < K; j++) {
			scanf("%d", &tmp);
			Adj[i].push_back(tmp);
		}
	}
	DFS(0, 0);
	double sum = P * pow(1 + r / 100, opt);
	printf("%.4f %d", sum, opt_count);
	return 0;
}