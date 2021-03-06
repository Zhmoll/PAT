#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int weight;
	vector<int> child;
};

vector<Node> node;
vector<int> tmp_path;
vector<vector<int>> ans_path;
int N, M, S, id, K, tmp;

bool cmp(int a, int b) {
	return node[a].weight > node[b].weight;
}

void DFS(int current, int sum) {
	if (node[current].child.size() == 0) {
		if (sum == S) {
			ans_path.push_back(tmp_path);
		}
		return;
	}

	for (int i = 0; i < node[current].child.size(); i++) {
		int child = node[current].child[i];
		tmp_path.push_back(node[child].weight);
		DFS(child, sum + node[child].weight);
		tmp_path.pop_back();
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &S);
	node.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &node[i].weight);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &id, &K);
		for (int j = 0; j < K; j++) {
			scanf("%d", &tmp);
			node[id].child.push_back(tmp);
		}
		sort(node[id].child.begin(), node[id].child.end(), cmp);
	}
	int root = 0;
	tmp_path.push_back(node[root].weight);
	DFS(root, node[root].weight);
	for (int i = 0; i < ans_path.size(); i++) {
		for (int j = 0; j < ans_path[i].size(); j++) {
			printf("%d", ans_path[i][j]);
			if (j != ans_path[i].size() - 1) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}