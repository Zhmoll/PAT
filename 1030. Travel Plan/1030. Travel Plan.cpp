#include <cstdio>
#include <vector>
#include <set>
#define INF 1e9
using namespace std;

struct Node {
	int distance;
	int cost;
	int to;
	Node(int to, int dis, int cost) :distance(dis), cost(cost), to(to) {};
};

int N, M, S, D;
vector<vector<Node>> G;
vector<bool> visited;
vector<set<int>> pre;
vector<int> path, temp_path;
vector<int> d;
int opt_value = INF;

void Dijkstra(int start) {
	visited.resize(N);
	fill(visited.begin(), visited.end(), false);
	d.resize(N);
	fill(d.begin(), d.end(), INF);
	d[start] = 0;
	pre.resize(N);

	for (int i = 0; i < N; i++) {
		int u = -1, min = INF;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && d[j] < min) {
				min = d[j];
				u = j;
			}
		}
		if (u == -1) return;
		visited[u] = true;

		for (int j = 0; j < G[u].size(); j++) {
			int v = G[u][j].to;
			int uv_len = G[u][j].distance;
			if (!visited[v] && d[u] + uv_len < d[v]) {
				d[v] = d[u] + uv_len;
				pre[v].clear();
				pre[v].insert(u);
			}
			else if (!visited[v] && d[u] + uv_len == d[v]) {
				pre[v].insert(u);
			}
		}
	}
}

void DFS(int start, int current) {
	if (start == current) {
		temp_path.push_back(current);
		int temp_value = 0;
		for (int i = temp_path.size() - 1; i > 0; i--) {
			int posi = temp_path[i];
			int next_posi = temp_path[i - 1];
			int cost;
			for (int j = 0; j < G[posi].size(); j++) {
				if (G[posi][j].to == next_posi) {
					cost = G[posi][j].cost;
					break;
				}
			}
			temp_value += cost;
		}
		if (temp_value < opt_value) {
			opt_value = temp_value;
			path = temp_path;
		}

		temp_path.pop_back();
		return;
	}

	temp_path.push_back(current);
	set<int>::iterator it = pre[current].begin();
	for (int i = 0; i < pre[current].size(); it++, i++) {
		DFS(start, *it);
	}
	temp_path.pop_back();
}

int main() {
	scanf("%d%d%d%d", &N, &M, &S, &D);
	G.resize(N);
	int c1, c2, dis, cost;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d%d", &c1, &c2, &dis, &cost);
		G[c1].push_back(Node(c2, dis, cost));
		G[c2].push_back(Node(c1, dis, cost));
	}
	Dijkstra(S);
	DFS(S, D);
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%d ", path[i]);
	}
	printf("%d %d", d[D], opt_value);
	return 0;
}