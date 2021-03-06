#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

struct Node {
	int v, w;
};

vector<int> ve, vl;
vector<vector<Node>> Adj;
vector<int> inDegree;
stack<int> topOrder;
int N;

bool topologicalSort() {
	queue<int> q;
	for (int i = 0; i < N; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		topOrder.push(u);
		for (int i = 0; i < Adj[u].size(); i++) {
			int v = Adj[u][i].v;
			inDegree[v]--;
			if (inDegree[v] == 0) {
				q.push(v);
			}
			if (ve[u] + Adj[u][i].w > ve[v]) {
				ve[v] = ve[u] + Adj[u][i].w;
			}
		}
	}
	if (topOrder.size() == N) return true;
	else return false;
}

int criticalPath() {
	ve.resize(N);
	if (topologicalSort() == false) {
		return -1;
	}
	vl.resize(N, ve[N - 1]);

	while (!topOrder.empty()) {
		int u = topOrder.top();
		topOrder.pop();
		for (int i = 0; i < Adj[u].size(); i++) {
			int v = Adj[u][i].v;
			if (vl[v] - Adj[u][i].w < vl[u]) {
				vl[u] = vl[v] - Adj[u][i].w;
			}
		}
	}

	for (int u = 0; u < N; u++) {
		for (int i = 0; i < Adj[u].size(); i++) {
			int v = Adj[u][i].v;
			int w = Adj[u][i].w;
			int e = ve[u];
			int l = vl[v] - w;
			if (e == l) {
				printf("%d->%d\n", u, w);
			}
		}
	}
	return ve[N - 1];
}