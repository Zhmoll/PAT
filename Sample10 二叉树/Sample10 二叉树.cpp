#include <cstdio>
#include <vector>
using namespace std;

struct Node {
	int data;
	Node *lchild, *rchild;
};

void search(Node* root, int x) {
	if (root == NULL) {
		printf("找不到");
		return;
	}
	if (x == root->data) {
		printf("%d\n", root->data);
	}
	else if (x < root->data) {
		search(root->lchild, x);
	}
	else {
		search(root->rchild, x);
	}
}

void insert(Node* &root, int x) {
	if (root == NULL) {
		root = new Node;
		root->lchild = root->rchild = NULL;
		root->data = x;
	}
	if (x == root->data) {
		return;
	}
	else if (x < root->data) {
		insert(root->lchild, x);
	}
	else {
		insert(root->rchild, x);
	}
}

Node* findMax(Node* root) {
	while (root->rchild != NULL) {
		root = root->rchild;
	}
	return root;
}

Node* findMin(Node* root) {
	while (root->lchild != NULL) {
		root = root->lchild;
	}
	return root;
}

void deleteNode(Node* &root, int x) {
	if (root == NULL) return;
	if (root->data == x) {
		if (root->lchild == NULL && root->rchild == NULL) {
			root = NULL;
		}
		else if (root->lchild != NULL) {
			Node* pre = findMax(root->lchild);
			root->data = pre->data;
			deleteNode(root->lchild, pre->data);
		}
		else {
			Node* next = findMin(root->rchild);
			root->data = next->data;
			deleteNode(root->rchild, next->data);
		}
	}
	else if (root->data > x) {
		deleteNode(root->lchild, x);
	}
	else {
		deleteNode(root->rchild, x);
	}
}

int main() {

	return 0;
}