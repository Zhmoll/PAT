#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int>> edge;
vector<bool> visited;
int liantong_count;
void DFS(int city) {
	visited[city] = true;
	for (int i = 0; i < edge[city].size(); i++) {
		if (!visited[edge[city][i]]) {
			DFS(edge[city][i]);
		}
	}
}

void  DFSTrave(int concern) {
	// 初始化
	liantong_count = 0;
	fill(visited.begin(), visited.end(), false);
	visited[concern] = true;
	// 开始遍历
	for (int i = 1; i < edge.size(); i++) {
		if (!visited[i]) {
			DFS(i);
			liantong_count++;
		}
	}
}

int main() {
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	edge.resize(N + 1);
	visited.resize(N + 1);
	int city1, city2, city_concern;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &city1, &city2);
		// 无向图
		edge[city1].push_back(city2);
		edge[city2].push_back(city1);
	}
	for (int i = 0; i < K; i++) {
		scanf("%d", &city_concern);
		DFSTrave(city_concern);
		printf("%d\n", liantong_count - 1);
	}
	return 0;
}