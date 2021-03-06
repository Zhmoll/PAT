#include <cstdio>
#include <set>
#define INF 100000000
using namespace std;

const int MAXN = 501;
int dist[MAXN][MAXN];
int cost[MAXN][MAXN];
int d[MAXN];
bool visited[MAXN];
int N, M, S, D;
int pre[MAXN];
int opt_cost[MAXN];

void dijkstra(int s) {
	fill(d, d + MAXN, INF);
	fill(visited, visited + MAXN, false);
	fill(opt_cost, opt_cost + MAXN, INF);
	for (int i = 0; i < MAXN; i++) pre[i] = i;
	d[s] = 0;
	opt_cost[s] = 0;

	for (int i = 0; i < N; i++) {
		int u = -1, min = INF;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && d[j] < min) {
				min = d[j];
				u = j;
			}
		}
		if (u == -1)return;
		visited[u] = true;

		for (int j = 0; j < N; j++) {
			int v = j;
			int len_uv = dist[u][v];
			if (!visited[v] && len_uv != INF) {
				if (d[u] + len_uv < d[v]) {
					d[v] = d[u] + len_uv;
					pre[v] = u;
					opt_cost[v] = opt_cost[u] + cost[u][v];
				}
				else if (d[u] + len_uv == d[v]) {
					if (cost[u][v] + opt_cost[u] < opt_cost[v]) {
						pre[v] = u;
						opt_cost[v] = cost[u][v] + opt_cost[u];
					}
				}
			}
		}
	}
}

void DFS(int current) {
	if (current == S) {
		printf("%d ", S);
		return;
	}

	DFS(pre[current]);
	printf("%d ", current);
}

int main() {
	scanf("%d%d%d%d", &N, &M, &S, &D);
	int c1, c2, spend, dis;
	fill(dist[0], dist[0] + MAXN * MAXN, INF);
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d%d", &c1, &c2, &dis, &spend);
		dist[c1][c2] = dis;
		dist[c2][c1] = dis;
		cost[c1][c2] = spend;
		cost[c2][c1] = spend;
	}
	dijkstra(S);
	DFS(D);
	printf("%d %d", d[D], opt_cost[D]);
	return 0;
}