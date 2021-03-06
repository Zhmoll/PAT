#include <cstdio>
#include <vector>
#include <set>
#define INF 1000000000
using namespace std;
struct Node {
	int to, time;
	Node(int to, int time) :to(to), time(time) {};
};

int capacity, N, S, M;
vector<vector<Node>> edge;
vector<set<int>> pre;
vector<int> bike;
vector<int> d;

void Dijkstra() {
	vector<bool> visited(N + 1);
	fill(visited.begin(), visited.end(), false);
	d.resize(N + 1);
	fill(d.begin(), d.end(), INF);
	d[0] = 0;
	pre.resize(N + 1);
	for (int i = 0; i <= N; i++) {
		int u = -1, min = INF;
		for (int j = 0; j <= N; j++) {
			if (!visited[j] && d[j] < min) {
				min = d[j];
				u = j;
			}
		}
		if (u == -1) return;
		visited[u] = true;
		for (int j = 0; j < edge[u].size(); j++) {
			int v = edge[u][j].to;
			int time = edge[u][j].time;
			if (!visited[v] && d[u] + time < d[v]) {
				d[v] = d[u] + time;
				pre[v].clear();
				pre[v].insert(u);
			}
			else if (!visited[v] && d[u] + time == d[v]) {
				pre[v].insert(u);
			}
		}
	}
}

vector<int> temp_path, path;
int opt_need = INF, opt_back = INF;

void DFS(int current) {
	if (0 == current) {
		int need = 0, back = 0, temp = 0;
		for (int i = temp_path.size() - 1; i >= 0; i--) {
			int id = temp_path[i];
			if (bike[id] + temp <= capacity / 2) {
				need += capacity / 2 - bike[id] - temp;
				temp = 0;
			}
			else {
				temp += bike[id] - capacity / 2;
			}
		}
		back = temp;
		if (need < opt_need) {
			opt_need = need;
			opt_back = back;
			path = temp_path;
		}
		else if (need == opt_need && back < opt_back) {
			opt_back = back;
			path = temp_path;
		}
		return;
	}

	set<int>::iterator it = pre[current].begin();
	temp_path.push_back(current);
	for (; it != pre[current].end(); it++) {
		DFS(*it);
	}
	temp_path.pop_back();
}

int main() {
	scanf("%d%d%d%d", &capacity, &N, &S, &M);
	edge.resize(N + 1);
	bike.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &bike[i]);
	}
	for (int i = 0; i < M; i++) {
		int c1, c2, count;
		scanf("%d%d%d", &c1, &c2, &count);
		edge[c1].push_back(Node(c2, count));
		edge[c2].push_back(Node(c1, count));
	}
	Dijkstra();
	DFS(S);
	printf("%d 0->", opt_need);
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%d", path[i]);
		if (i != 0) printf("->");
	}
	printf(" %d", opt_back);

	return 0;
}