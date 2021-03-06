#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	vector<int> child;
};

vector<Node> Adj;

void levelOrder() {
	queue<int> q;
	q.push(1);
	int gen = 0;
	int opt_len = 0;
	int opt_gen = 0;
	while (!q.empty()) {
		int len = q.size();
		gen++;
		if (len > opt_len) {
			opt_len = len;
			opt_gen = gen;
		}
		for (int i = 0; i < len; i++) {
			int current = q.front();
			q.pop();
			for (int j = 0; j < Adj[current].child.size(); j++) {
				q.push(Adj[current].child[j]);
			}
		}
	}
	printf("%d %d", opt_len, opt_gen);
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	Adj.resize(N + 1);
	int id, K, tmp;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &id, &K);
		for (int j = 0; j < K; j++) {
			scanf("%d", &tmp);
			Adj[id].child.push_back(tmp);
		}
	}
	levelOrder();
	return 0;
}