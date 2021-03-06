#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int lchild, rchild;
	int data;
}node[105];

int N;
int posi = 0;
vector<int> input;

void inOrder(int current) {
	if (current == -1) return;
	inOrder(node[current].lchild);
	node[current].data = input[posi++];
	inOrder(node[current].rchild);
}

vector<int> ans;

void levelOrder(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		if (current == -1) continue;
		ans.push_back(node[current].data);
		q.push(node[current].lchild);
		q.push(node[current].rchild);
	}
}

int main() {
	scanf("%d", &N);
	int l, r, tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &l, &r);
		node[i].lchild = l;
		node[i].rchild = r;
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		input.push_back(tmp);
	}
	sort(input.begin(), input.end());
	inOrder(0);
	levelOrder(0);
	for (int i = 0; i < N; i++) {
		printf("%d", ans[i]);
		if (i != N - 1) printf(" ");
	}
	return 0;
}