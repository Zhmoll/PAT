#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int data;
	Node *lchild, *rchild;
};

void insert(Node* &root, int data) {
	if (root == NULL) {
		root = new Node;
		root->data = data;
		root->lchild = root->rchild = NULL;
		return;
	}

	if (data < root->data) {
		insert(root->lchild, data);
	}
	else {
		insert(root->rchild, data);
	}
}

vector<int> input;
int lca;

void search(Node* root, int u, int v) {
	if (root == NULL) return;
	lca = root->data;
	if (root->data == u) return;
	else if (root->data == v) return;
	else if (u < root->data && v < root->data) search(root->lchild, u, v);
	else if (u > root->data && v > root->data) search(root->rchild, u, v);
}

int main() {
	int M, N, tmp;
	scanf("%d%d", &M, &N);
	Node* root = NULL;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		insert(root, tmp);
		input.push_back(tmp);
	}
	sort(input.begin(), input.end());
	int u, v;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &u, &v);
		bool uexisted = binary_search(input.begin(), input.end(), u);
		bool vexisted = binary_search(input.begin(), input.end(), v);
		if (!uexisted && vexisted) {
			printf("ERROR: %d is not found.\n", u);
			continue;
		}
		else if (uexisted && !vexisted) {
			printf("ERROR: %d is not found.\n", v);
			continue;
		}
		else if (!uexisted && !vexisted) {
			printf("ERROR: %d and %d are not found.\n", u, v);
			continue;
		}

		search(root, u, v);
		if (lca == u || lca == v) {
			printf("%d is an ancestor of %d.\n", lca, lca == u ? v : u);
		}
		else {
			printf("LCA of %d and %d is %d.\n", u, v, lca);
		}
	}
	return 0;
}