#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> Adj;

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	Adj.resize(N + 1);
	int id, K, tmp;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &id, &K);
		for (int j = 0; j < K; j++) {
			scanf("%d", &tmp);
			Adj[id].push_back(tmp);
		}
	}

	queue<int> q;
	q.push(1);
	vector<int> ans;
	while (!q.empty()) {
		int len = q.size();
		int cnt = 0;
		for (int i = 0; i < len; i++) {
			int current = q.front();
			q.pop();
			if (Adj[current].size() != 0)cnt++;
			for (int j = 0; j < Adj[current].size(); j++) {
				q.push(Adj[current][j]);
			}
		}
		ans.push_back(len - cnt);
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%d", ans[i]);
		if (i != ans.size() - 1) printf(" ");
	}
	return 0;
}