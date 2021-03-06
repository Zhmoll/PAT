#include <cstdio>
#include <vector>
#include <set>
#define INF 1000000000
using namespace std;

struct Node {
	int to, distance;
	Node(int to, int dis) :to(to), distance(dis) {};
};

int N, M, C1, C2;
vector<vector<Node>> Adj;
vector<int> weight;
vector<int> d;
vector<set<int>> pre;

bool BellmanFord(int start) {
	d.resize(N);
	fill(d.begin(), d.end(), INF);
	d[start] = 0;
	pre.resize(N);
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N; j++) {
			int u = j;
			for (int k = 0; k < Adj[u].size(); k++) {
				int v = Adj[u][k].to;
				int distance = Adj[u][k].distance;
				if (d[u] + distance < d[v]) {
					d[v] = d[u] + distance;
					pre[v].clear();
					pre[v].insert(u);
				}
				else if (d[u] + distance == d[v]) {
					pre[v].insert(u);
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		int u = i;
		for (int j = 0; j < Adj[u].size(); j++) {
			int v = Adj[u][j].to;
			int distance = Adj[u][j].distance;
			if (d[u] + distance < d[v])
				return false;
		}
	}
	return true;
}

vector<int> tmp_path, path;
int opt_value = 0;
int path_count = 0;

void DFS(int current) {
	if (C1 == current) {
		tmp_path.push_back(current);
		int value = 0;
		for (int i = tmp_path.size() - 1; i >= 0; i--) {
			int id = tmp_path[i];
			value += weight[id];
		}
		if (value > opt_value) {
			opt_value = value;
			path = tmp_path;
		}
		tmp_path.pop_back();
		path_count++;
		return;
	}

	set<int>::iterator it = pre[current].begin();
	tmp_path.push_back(current);
	for (; it != pre[current].end(); it++) {
		DFS(*it);
	}
	tmp_path.pop_back();
}

int main() {
	scanf("%d%d%d%d", &N, &M, &C1, &C2);
	Adj.resize(N);
	weight.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &weight[i]);
	}
	int c1, c2, length;
	for (int j = 0; j < M; j++) {
		scanf("%d %d %d", &c1, &c2, &length);
		Adj[c1].push_back(Node(c2, length));
		Adj[c2].push_back(Node(c1, length));
	}
	BellmanFord(C1);
	DFS(C2);
	printf("%d %d", path_count, opt_value);
	return 0;
}