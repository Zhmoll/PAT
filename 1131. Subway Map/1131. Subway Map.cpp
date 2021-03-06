#include <cstdio>
#include <vector>
using namespace std;
int N;
struct station {
	int id;
	int to;
	int belongsTo;
	station(int id, int to, int belongsTo) :id(id), to(to), belongsTo(belongsTo) {};
};

vector<station> node[10005];
bool visited[10005];
vector<station*> tmp_path, path;
// int opt_transfer = 0;

int calcTransfer(vector<station*> p) {
	int result = 0;
	int last = p[0]->belongsTo;
	for (int i = 1; i < p.size(); i++) {
		if (p[i]->belongsTo != last) {
			result++;
			last = p[i]->belongsTo;
		}
	}
	return result;
}

void DFS(int current, int end) {
	if (current == end) {
		if (path.size() == 0 || tmp_path.size() < path.size()) {
			path = tmp_path;
		}
		else if (tmp_path.size() == path.size()) {
			// 计算transfer
			if (calcTransfer(tmp_path) < calcTransfer(path)) {
				path = tmp_path;
			}
		}
		return;
	}

	for (int i = 0; i < node[current].size(); i++) {
		if (visited[node[current][i].to]) continue;
		visited[node[current][i].to] = true;
		tmp_path.push_back(&node[current][i]);

		DFS(node[current][i].to, end);

		visited[node[current][i].to] = false;
		tmp_path.pop_back();
	}
}

void DFSTrave(int start, int end) {
	fill(visited, visited + 10005, false);
	visited[start] = true;
	tmp_path.clear();
	path.clear();
	DFS(start, end);
}

void printPath(int start) {
	printf("%d\n", path.size());
	int last = path[0]->belongsTo;
	int from = start;
	for (int i = 0; i <= path.size(); i++) {
		while (i < path.size() && path[i]->belongsTo == last) i++;
		printf("Take Line#%d from %04d to %04d.\n", last, from, path[i-1]->to);
		if (i < path.size()) last = path[i]->belongsTo;
		from = path[i-1]->to;
	}
}

int main() {
	scanf("%d", &N);
	int S, tmp;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &S);
		int last = -1;
		for (int j = 0; j < S; j++) {
			scanf("%d", &tmp);
			if (j == 0) last = tmp;
			else {
				node[last].push_back(station(last, tmp, i));
				node[tmp].push_back(station(tmp, last, i));
				last = tmp;
			}
		}
	}
	int K, from, to;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &from, &to);
		DFSTrave(from, to);
		printPath(from);
	}
	return 0;
}