#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#define INF 1000000000
using namespace std;

struct Node {
	int to;
	int length;
	Node(int to, int length) :to(to), length(length) {};
};
int N, M, K, D;
vector<vector<Node>> Adj;
vector<int> d;

void Dijkstra(int start) {
	vector<bool> visited(N + M + 1);
	d.resize(N + M + 1);
	for (int i = 1; i <= N + M; i++) {
		visited[i] = false;
		d[i] = INF;
	}
	d[start] = 0;
	for (int i = 0; i < M + N; i++) {
		int u = -1, min = INF;
		for (int j = 1; j <= M + N; j++) {
			if (!visited[j] && d[j] < min) {
				min = d[j];
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
			}
		}
	}
}

bool checkInRange() {
	for (int i = 1; i <= N; i++)
		if (d[i] > D) return false;
	return true;
}

int main() {
	scanf("%d%d%d%d", &N, &M, &K, &D);
	Adj.resize(N + M + 1);
	char p1[5], p2[5];
	int len;
	for (int i = 0; i < K; i++) {
		scanf("%s %s %d", p1, p2, &len);
		if (p1[0] != 'G' && p2[0] != 'G') {
			Adj[stoi(p1)].push_back(Node(stoi(p2), len));
			Adj[stoi(p2)].push_back(Node(stoi(p1), len));
		}
		else if (p1[0] != 'G' && p2[0] == 'G') {
			char newp2[5];
			strcpy(newp2, p2 + 1);
			Adj[stoi(p1)].push_back(Node(stoi(newp2) + N, len));
			Adj[stoi(newp2) + N].push_back(Node(stoi(p1), len));
		}
		else if (p1[0] == 'G' && p2[0] != 'G') {
			char newp1[5];
			strcpy(newp1, p1 + 1);
			Adj[stoi(newp1) + N].push_back(Node(stoi(p2), len));
			Adj[stoi(p2)].push_back(Node(stoi(newp1) + N, len));
		}
		else if (p1[0] == 'G' && p2[0] == 'G') {
			char newp1[5], newp2[5];
			strcpy(newp1, p1 + 1);
			strcpy(newp2, p2 + 1);
			Adj[stoi(newp1) + N].push_back(Node(stoi(newp2) + N, len));
			Adj[stoi(newp2) + N].push_back(Node(stoi(newp1) + N, len));
		}
	}

	int opt_min_distance = 0;
	double opt_avg_distance = INF;
	int opt_station = -1;
	for (int i = 1; i <= M; i++) {
		Dijkstra(i + N);
		if (checkInRange()) {
			int u = -1, min = INF;
			int total_distance = 0;
			for (int j = 1; j <= N; j++) {
				if (d[j] < min) {
					min = d[j];
					u = j;
				}
				total_distance += d[j];
			}
			double avg_distance = (1.0*total_distance) / N;
			if (min > opt_min_distance) {
				opt_min_distance = min;
				opt_avg_distance = avg_distance;
				opt_station = i;
			}
			else if (min == opt_min_distance) {
				if (avg_distance < opt_avg_distance) {
					opt_min_distance = min;
					opt_avg_distance = avg_distance;
					opt_station = i;
				}
			}
		}
	}

	if (opt_station == -1) {
		printf("No Solution");
	}
	else {
		printf("G%d\n", opt_station);
		printf("%d.0 %.1f", opt_min_distance, opt_avg_distance);
	}
	return 0;
}