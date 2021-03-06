#include <cstdio>
#include <vector>
#define INF 1e9
using namespace std;

struct Node {
	int to;
	int len;
	Node(int to, int len) :to(to), len(len) {};
};

vector<vector<Node>> length;
vector<int> totalTeam;
vector<int> d;
vector<bool> visited;
vector<int> path_count;
vector<int> team_count;
int N; // N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1)
int M; // M - the number of roads

void Dijkstra(int start) {
	d.resize(N);
	visited.resize(N);
	path_count.resize(N);
	team_count.resize(N);
	fill(d.begin(), d.end(), INF);
	fill(visited.begin(), visited.end(), false);
	d[start] = 0;
	path_count[start] = 1;
	team_count[start] = totalTeam[start];

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

		for (int j = 0; j < length[u].size(); j++) {
			int v = length[u][j].to;
			int len_uv = length[u][j].len;
			if (!visited[v]) {
				if (d[u] + len_uv < d[v]) {
					d[v] = d[u] + len_uv;
					team_count[v] = team_count[u] + totalTeam[v];
					path_count[v] = path_count[u];
				}
				else if (d[u] + len_uv == d[v]) {
					if (team_count[v] < team_count[u] + totalTeam[v])
						team_count[v] = team_count[u] + totalTeam[v];
					path_count[v] += path_count[u];
				}
			}
		}
	}
}

int main() {
	int C1, C2; // C1起点，C2终点
	scanf("%d%d%d%d", &N, &M, &C1, &C2);
	length.resize(N);
	totalTeam.resize(N);
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &totalTeam[i]);
	}
	int c1, c2, L;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &c1, &c2, &L);
		length[c1].push_back(Node(c2, L));
		length[c2].push_back(Node(c1, L));
	}
	Dijkstra(C1);
	printf("%d %d", path_count[C2], team_count[C2]);
	return 0;
}