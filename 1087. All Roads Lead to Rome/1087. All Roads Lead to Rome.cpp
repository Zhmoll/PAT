#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#define INF 1000000000
using namespace std;

struct Node {
	int to;
	int cost;
	Node(int to, int cost) :to(to), cost(cost) {};
};

vector<Node> Adj[26 * 26 * 26 + 5];

int N, K;
char start[4];
int weight[26 * 26 * 26 + 5];
int d[26 * 26 * 26 + 5];
set<int> pre[26 * 26 * 26 + 5];

inline int find(const char name[]) {
	return (name[0] - 'A') * 26 * 26 + (name[1] - 'A') * 26 + name[2] - 'A';
}

inline void toName(int num, char str[]) {
	str[2] = num % 26 + 'A';
	num /= 26;
	str[1] = num % 26 + 'A';
	num /= 26;
	str[0] = num + 'A';
	str[3] = '\0';
}

bool SPFA(int start) {
	vector<int> adj_count(26 * 26 * 26 + 5);
	vector<bool> inq(26 * 26 * 26 + 5);
	queue<int> q;
	q.push(start);
	inq[start] = true;
	adj_count[start] ++;
	fill(d, d + 26 * 26 * 26 + 5, INF);
	d[start] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int j = 0; j < Adj[u].size(); j++) {
			int v = Adj[u][j].to;
			int cost = Adj[u][j].cost;
			if (d[u] + cost < d[v]) {
				d[v] = d[u] + cost;
				pre[v].clear();
				pre[v].insert(u);
				if (!inq[v]) {
					q.push(v);
					inq[v] = true;
					adj_count[v]++;
					if (adj_count[v] >= N) return false;
				}
			}
			else if (d[u] + cost == d[v]) {
				pre[v].insert(u);
			}
		}
	}
}

vector<int> tmp_path, path;
int path_count = 0;
int opt_happiness = 0;
double avg_happiness = 0;

void DFS(int start, int current) {
	if (start == current) {
		tmp_path.push_back(current);
		int tmp_happiness = 0;
		int cost = 0;
		for (int i = tmp_path.size() - 1; i > 0; i--) {
			int id = tmp_path[i];
			int id_next = tmp_path[i - 1];
			int posi = -1;
			for (int j = 0; j < Adj[id].size(); j++) {
				if (Adj[id][j].to == id_next) {
					posi = j;
					break;
				}
			}
			cost += Adj[id][posi].cost;
		}
		for (int i = 0; i < tmp_path.size() - 1; i++) {
			tmp_happiness += weight[tmp_path[i]];
		}
		double tmp_avg_happiness = tmp_happiness / (tmp_path.size() - 1);

		if (tmp_happiness > opt_happiness) {
			opt_happiness = tmp_happiness;
			avg_happiness = tmp_avg_happiness;
			path = tmp_path;
		}
		else if (tmp_happiness == opt_happiness) {
			if (tmp_avg_happiness > avg_happiness) {
				opt_happiness = tmp_happiness;
				avg_happiness = tmp_avg_happiness;
				path = tmp_path;
			}
		}
		tmp_path.pop_back();
		path_count++;
		return;
	}

	set<int>::iterator it = pre[current].begin();
	tmp_path.push_back(current);
	for (; it != pre[current].end(); it++) {
		DFS(start, *it);
	}
	tmp_path.pop_back();
}

int main() {
	// the route with the least cost while gaining the most happiness
	scanf("%d %d %s", &N, &K, start);
	char name1[4], name2[4];
	int tmp;
	for (int i = 0; i < N - 1; i++) {
		scanf("%s %d", name1, &tmp);
		weight[find(name1)] = tmp;
	}
	for (int i = 0; i < K; i++) {
		scanf("%s %s %d", name1, name2, &tmp);
		Adj[find(name1)].push_back(Node(find(name2), tmp));
		Adj[find(name2)].push_back(Node(find(name1), tmp));
	}
	SPFA(find(start));
	DFS(find(start), find("ROM"));
	printf("%d %d %d %d\n", path_count, d[find("ROM")], opt_happiness, (int)avg_happiness);
	for (int i = path.size() - 1; i >= 0; i--) {
		toName(path[i], name1);
		printf("%s", name1);
		if (i != 0) printf("->");
	}
	return 0;
}