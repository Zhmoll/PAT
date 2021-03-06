#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int>> Adj;
vector<bool> visited;
int N, M;
bool flag = true;
void DFS(int current) {
	visited[current] = true;
	for (int i = 0; i < Adj[current].size(); i++) {
		if (!visited[Adj[current][i]]) {
			DFS(Adj[current][i]);
		}
	}
}

void DFSTrave(int odd1) {
	visited.resize(N + 1);
	fill(visited.begin(), visited.end(), false);
	int start = 1;
	if (odd1 != -1) {
		start = odd1;
	}
	DFS(start);
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) flag = false;
	}
}

int main() {

	scanf("%d %d", &N, &M);
	Adj.resize(N + 1);
	int c1, c2;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &c1, &c2);
		Adj[c1].push_back(c2);
		Adj[c2].push_back(c1);
	}
	int odd_count = 0;
	int odd1 = -1, odd2 = -1;
	for (int i = 1; i <= N; i++) {
		printf("%d", Adj[i].size());
		if (Adj[i].size() % 2 == 1) {
			odd_count++;
			if (odd_count == 1) odd1 = i;
			else if (odd_count == 2) odd2 = i;
		}
		if (i != N) printf(" ");
	}
	printf("\n");
	DFSTrave(odd1);
	if (flag && odd_count == 0) {
		printf("Eulerian");
	}
	else if (flag && odd_count == 2) {
		printf("Semi-Eulerian");
	}
	else {
		printf("Non-Eulerian");
	}

	return 0;
}