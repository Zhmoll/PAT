#include <cstdio>
#include <vector>
using namespace std;
struct node {
	char str[12];
	int lchild;
	int rchild;
};

int root = -1;

void inorder(vector<node> &tree, int i) {
	if (i == -1) return;
	int left = tree[i].lchild;
	int right = tree[i].rchild;
	if (left != -1 || right != -1) {
		if (i != root) printf("(");
		inorder(tree, left);
	}
	printf("%s", tree[i].str);
	if (left != -1 || right != -1) {
		inorder(tree, right);
		if (i != root) printf(")");
	}
}

int main() {
	int N;
	scanf("%d", &N);
	vector<node> tree(N + 1);
	vector<int> hash(N + 1);
	for (int i = 0; i < N; i++) {
		scanf("%s %d %d", tree[i + 1].str, &(tree[i + 1].lchild), &(tree[i + 1].rchild));
		if (tree[i + 1].lchild != -1) hash[tree[i + 1].lchild]++;
		if (tree[i + 1].rchild != -1) hash[tree[i + 1].rchild]++;
	}

	for (int i = 1; i <= N; i++) {
		if (hash[i] == 0) {
			root = i;
			break;
		}
	}

	inorder(tree, root);
	return 0;
}