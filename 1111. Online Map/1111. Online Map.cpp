#include <cstdio>
#include <vector>
#include <set>
#define INF 1000000000
using namespace std;

struct Node {
	int to;
	int length, time;
	Node(int to, int length, int time) :to(to), length(length), time(time) {};
};

int N, M;
vector<vector<Node>> Adj;
vector<int> d;
vector<int> t;
vector<int> pred;
vector<int> pret;

void Dijkstra_d(int start) {
	vector<bool> visited(N);
	fill(visited.begin(), visited.end(), false);
	vector<int> time(N);
	fill(time.begin(), time.end(), 0);
	d.resize(N);
	fill(d.begin(), d.end(), INF);
	d[start] = 0;
	pred.resize(N);
	for (int i = 0; i < N; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && d[j] < MIN) {
				MIN = d[j];
				u = j;
			}
		}
		if (u == -1) return;
		visited[u] = true;
		for (int j = 0; j < Adj[u].size(); j++) {
			int v = Adj[u][j].to;
			int len = Adj[u][j].length;
			if (!visited[v] && d[u] + len < d[v]) {
				d[v] = d[u] + len;
				pred[v] = u;
				time[v] = time[u] + Adj[u][j].time;
			}
			else if (!visited[v] && d[u] + len == d[v]) {
				if (time[u] + Adj[u][j].time < time[v]) {
					time[v] = time[u] + Adj[u][j].time;
					pred[v] = u;
				}
			}
		}

	}
}

void Dijkstra_t(int start) {
	vector<bool> visited(N);
	fill(visited.begin(), visited.end(), false);
	vector<int> node_count(N);
	fill(node_count.begin(), node_count.end(), 0);
	t.resize(N);
	fill(t.begin(), t.end(), INF);
	t[start] = 0;
	pret.resize(N);
	for (int i = 0; i < N; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && t[j] < MIN) {
				MIN = t[j];
				u = j;
			}
		}
		if (u == -1) return;
		visited[u] = true;
		for (int j = 0; j < Adj[u].size(); j++) {
			int v = Adj[u][j].to;
			int spend = Adj[u][j].time;
			if (!visited[v] && t[u] + spend < t[v]) {
				t[v] = t[u] + spend;
				pret[v] = u;
				node_count[v] = node_count[u] + 1;
			}
			else if (!visited[v] && t[u] + spend == t[v]) {
				if (node_count[u] + 1 < node_count[v]) {
					node_count[v] = node_count[u] + 1;
					pret[v] = u;
				}
			}
		}

	}
}

void DFS(int start, int current, int end, vector<int> &pre) {
	if (start == current) {
		printf("%d", start);
		printf(" -> ");
		return;
	}
	DFS(start, pre[current], end, pre);
	printf("%d", current);
	if (current != end)printf(" -> ");
}

int main() {
	scanf("%d%d", &N, &M);
	Adj.resize(N);
	int v1, v2, way, length, time;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d%d%d", &v1, &v2, &way, &length, &time);
		Adj[v1].push_back(Node(v2, length, time));
		if (way == 0) Adj[v2].push_back(Node(v1, length, time));
	}
	int S, D;
	scanf("%d%d", &S, &D);
	Dijkstra_d(S);
	Dijkstra_t(S);
	if (pred == pret) {
		printf("Distance = %d; Time = %d: ",d[D],t[D]);
		DFS(S, D, D, pred);
		printf("\n");
	}
	else {
		printf("Distance = %d: ", d[D]);
		DFS(S, D, D, pred);
		printf("\n");
		printf("Time = %d: ", t[D]);
		DFS(S, D, D, pret);
		printf("\n");
	}
	return 0;
}