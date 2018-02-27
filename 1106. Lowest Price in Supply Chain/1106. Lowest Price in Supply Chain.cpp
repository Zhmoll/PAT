#include <cstdio>
#include <vector>
#define INF 1000000000
using namespace std;
vector<vector<int>> Adj;
int opt_count = INF;
int tmp_count = 0;
int opt_count_count = 0;

void DFS(int current) {
	if (Adj[current].size() == 0) {
		if (tmp_count < opt_count) {
			opt_count = tmp_count;
			opt_count_count = 1;
		}
		else if (tmp_count == opt_count) {
			opt_count_count++;
		}
		return;
	}
	for (int i = 0; i < Adj[current].size(); i++) {
		tmp_count++;
		DFS(Adj[current][i]);
		tmp_count--;
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
	DFS(0);
	double sum = P;
	for (int i = 0; i < opt_count; i++) {
		sum *= 1 + r / 100;
	}
	printf("%.4lf %d", sum, opt_count_count);
	return 0;
}