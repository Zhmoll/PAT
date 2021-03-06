#include <cstdio>
struct Node {
	int data;
	Node* lchild;
	Node* rchild;
};

void insert(Node* &root, int data) {
	if (root == NULL) {
		root = new Node;
		root->data = data;
		root->lchild = NULL;
		root->rchild = NULL;
		return;
	}

	if (data <= root->data) {
		return insert(root->lchild, data);
	}
	else {
		return insert(root->rchild, data);
	}
}

int level = 0;
int count[1005] = { 0 };

void preOrder(Node* root) {
	if (root == NULL) return;
	level++;
	count[level]++;
	preOrder(root->lchild);
	preOrder(root->rchild);
	level--;
}

int main() {
	int N;
	scanf("%d", &N);
	Node* root = NULL;
	int data;
	for (int i = 0; i < N; i++) {
		scanf("%d", &data);
		insert(root, data);
	}
	preOrder(root);
	int i;
	for (i = 1; i <= 1000; i++) {
		if (count[i] == 0) {
			break;
		}
	}
	int lowest = i - 1;
	int lowest_above = i - 2;
	printf("%d + %d = %d", count[lowest], count[lowest_above], count[lowest] + count[lowest_above]);

	return 0;
}