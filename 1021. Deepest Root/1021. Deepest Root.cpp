#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> v;
vector<bool> visited;
int main() {
	int N;
	scanf("%d", &N);
	v.resize(N + 1);
	visited.resize(N + 1);
	int v1, v2;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d%d", &v1, &v2);
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}

	// BFS
	vector<int> deepest_level(N + 1);
	int deepest_length = 0;
	int comp = 1;
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		int root = i;
		fill(visited.begin(), visited.end(), false);
		visited[root] = true;
		while (!q.empty()) q.pop();
		q.push(root);

		int level = 0;
		while (q.size() != 0) {
			int len = q.size();
			level++;
			if (deepest_level[i] < level) {
				deepest_level[i] = level;
				if (deepest_length < level) {
					deepest_length = level;
				}
			}
			for (int j = 0; j < len; j++) {
				int current = q.front();
				q.pop();
				for (int k = 0; k < v[current].size(); k++) {
					if (!visited[v[current][k]]) {
						q.push(v[current][k]);
						visited[v[current][k]] = true;
					}
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				queue<int> q;
				q.push(i);
				comp++;
				while (q.size() != 0) {
					int current = q.front();
					q.pop();
					for (int i = 0; i < v[current].size(); i++) {
						if (!visited[v[current][i]]) {
							visited[v[current][i]] = true;
							q.push(v[current][i]);
						}
					}
				}
			}
		}
		if (comp != 1) {
			break;
		}
	}

	if (comp != 1) {
		printf("Error: %d components", comp);
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (deepest_level[i] == deepest_length)
				printf("%d\n", i);
		}
	}

	return 0;
}