#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int weight[105] = { 0 };

bool cmp(int a, int b) {
	return weight[a] > weight[b];
}

vector<int> q;

void checkWeight(vector<vector<int>> &tree, int i,int S) {
	int sum = 0;
	if (tree[i].size() != 0) return;// 非叶节点
	for (int i = 0; i < q.size(); i++) {
		sum += weight[q[i]];
	}
	if (sum == S) {
		for (int i = 0; i < q.size(); i++) {
			printf("%d", weight[q[i]]);
			if (i != q.size() - 1) printf(" ");
		}
		printf("\n");
	}
}

void preOrder(vector<vector<int>> &tree, int root, int S) {
	checkWeight(tree, root, S);
	for (int i = 0; i < tree[root].size(); i++) {
		q.push_back(tree[root][i]);
		preOrder(tree, tree[root][i],S);
		q.pop_back();
	}
}

int main() {
	int N, M, S;
	scanf("%d %d %d",&N,&M,&S);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", weight + i);
	}

	vector<vector<int>> tree(N);
	for (int i = 0; i < M; i++) {
		int id, K;
		scanf("%d %d", &id, &K);
		for (int j = 0; j < K; j++) {
			int tmp;
			scanf("%d", &tmp);
			tree[id].push_back(tmp);
		}
		sort(tree[id].begin(), tree[id].end(), cmp);
	}

	q.push_back(0);
	preOrder(tree, 0, S);

	return 0;
}