#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> follow;
vector<bool> visited;
int levelThreshold;
int BFS(int start) {
	fill(visited.begin(), visited.end(), false);
	visited[start] = true;
	int level = 0;
	int foward_count = 0;
	queue<int> q;
	q.push(start);
	while (q.size() != 0) {
		level++;
		if (level > levelThreshold) break;
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int current = q.front();
			q.pop();
			for (int j = 0; j < follow[current].size(); j++) {
				if (!visited[follow[current][j]]) {
					foward_count++;
					visited[follow[current][j]] = true;
					q.push(follow[current][j]);
				}
			}
		}
	}
	return foward_count;
}

int main() {
	int N, L;
	scanf("%d%d", &N, &L);
	follow.resize(N + 1);
	visited.resize(N + 1);
	levelThreshold = L;
	int M, tmp;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &M);
		for (int j = 0; j < M; j++) {
			scanf("%d", &tmp);
			follow[tmp].push_back(i);
		}
	}
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &tmp);
		printf("%d\n", BFS(tmp));
	}
	return 0;
}