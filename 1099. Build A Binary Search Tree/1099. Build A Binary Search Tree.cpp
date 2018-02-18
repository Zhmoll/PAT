#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int data;
	int lchild, rchild;
}node[105];

vector<int> input;
int current = 0;
void inorder(int root) {
	if (root == -1) return;
	inorder(node[root].lchild);
	node[root].data = input[current++];
	inorder(node[root].rchild);
}

void levelorder(int root) {
	queue<int> level;
	level.push(root);
	while (level.size() > 0) {
		int current = level.front();
		level.pop();
		if (node[current].lchild != -1) level.push(node[current].lchild);
		if (node[current].rchild != -1) level.push(node[current].rchild);
		printf("%d", node[current].data);
		if (level.size() != 0) printf(" ");
	}
}

int main() {
	int N;
	scanf("%d", &N);
	int root = 0;
	int lchild, rchild;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &lchild, &rchild);
		node[i].lchild = lchild;
		node[i].rchild = rchild;
	}
	int key;
	for (int i = 0; i < N; i++) {
		scanf("%d", &key);
		input.push_back(key);
	}
	sort(input.begin(), input.end());
	inorder(root);
	levelorder(root);
	return 0;
}