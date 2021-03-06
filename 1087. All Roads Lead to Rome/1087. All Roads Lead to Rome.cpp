#include <cstdio>
#include <vector>
#define INF 1000000000
using namespace std;

struct Node {
	int v;
	int cost;
	Node(int v, int cost) :v(v), cost(cost) {}
};

vector<int> input;
vector<Node> Adj[26 * 26 * 26 + 5];
vector<vector<int>> pre;
int d[26 * 26 * 26 + 5];
int weight[26 * 26 * 26 + 5];

int name_to_int(const char name[]) {
	return (name[0] - 'A') * 26 * 26 + (name[1] - 'A') * 26 + (name[2] - 'A');
}

void int_to_name(int num, char name[]) {
	name[2] = num % 26 + 'A';
	num /= 26;
	name[1] = num % 26 + 'A';
	num /= 26;
	name[0] = num + 'A';
}

void Dijkstra(int start) {
	vector<bool> visited(26 * 26 * 26 + 5, false);
	pre.resize(26 * 26 * 26 + 5);
	fill(d, d + 26 * 26 * 26 + 5, INF);
	d[start] = 0;

	for (int i = 0; i < input.size(); i++) {
		int u = -1;
		int min = INF;
		for (int j = 0; j < input.size(); j++) {
			if (!visited[input[j]] && d[input[j]] < min) {
				min = d[input[j]];
				u = input[j];
			}
		}
		if (u == -1) return;
		visited[u] = true;
		for (int j = 0; j < Adj[u].size(); j++) {
			int v = Adj[u][j].v;
			int cost = Adj[u][j].cost;
			if (!visited[v] && d[u] + cost < d[v]) {
				d[v] = d[u] + cost;
				pre[v].clear();
				pre[v].push_back(u);
			}
			else if (!visited[v] && d[u] + cost == d[v]) {
				pre[v].push_back(u);
			}
		}
	}
}

vector<int> tmp_path, path;
int opt = 0;
int cnt = 0;

void DFS(int start, int current, int sum_happy) {
	if (current == start) {
		tmp_path.push_back(current);
		if (sum_happy > opt) {
			opt = sum_happy;
			path = tmp_path;
		}
		tmp_path.pop_back();
		cnt++;
		return;
	}

	tmp_path.push_back(current);
	for (int i = 0; i < pre[current].size(); i++) {
		DFS(start, pre[current][i], sum_happy + weight[pre[current][i]]);
	}
	tmp_path.pop_back();
}

int main() {
	int N, K, happy;
	char start[5], tmp[5];
	scanf("%d %d %s", &N, &K, start);
	input.push_back(name_to_int(start));
	for (int i = 0; i < N - 1; i++) {
		scanf("%s %d", tmp, &happy);
		weight[name_to_int(tmp)] = happy;
		input.push_back(name_to_int(tmp));
	}

	char p1[5], p2[5];
	int cost;
	for (int i = 0; i < K; i++) {
		scanf("%s %s %d", p1, p2, &cost);
		int index1 = name_to_int(p1);
		int index2 = name_to_int(p2);
		Adj[index1].push_back(Node(index2, cost));
		Adj[index2].push_back(Node(index1, cost));
	}

	Dijkstra(name_to_int(start));
	DFS(name_to_int(start), name_to_int("ROM"), weight[name_to_int("ROM")]);
	printf("%d %d %d %d\n", cnt, d[name_to_int("ROM")], opt, opt / (path.size() - 1));
	for (int i = path.size() - 1; i >= 0; i--) {
		int_to_name(path[i], tmp);
		printf("%s", tmp);
		if (i > 0) printf("->");
	}

	return 0;
}