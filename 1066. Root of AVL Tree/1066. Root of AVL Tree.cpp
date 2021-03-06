#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int data;
	Node *lchild, *rchild;
	int height;
};

Node* newNode(int data) {
	Node* node = new Node;
	node->data = data;
	node->lchild = node->rchild = NULL;
	node->height = 1;
	return node;
}

int getHeight(Node* root) {
	if (root == NULL) return 0;
	else return root->height;
}

int getBalance(Node* root) {
	if (root == NULL) return 0;
	return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(Node* root) {
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

void L(Node* &root) {
	Node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void R(Node* &root) {
	Node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void insert(Node* &root, int data) {
	if (root == NULL) {
		root = newNode(data);
		return;
	}

	if (data < root->data) {
		insert(root->lchild, data);
		updateHeight(root);
		if (getBalance(root) == 2) {
			if (getBalance(root->lchild) == 1) {
				R(root);
			}
			else if (getBalance(root->lchild) == -1) {
				L(root->lchild);
				R(root);
			}
		}
	}
	else {
		insert(root->rchild, data);
		updateHeight(root);
		if (getBalance(root) == -2) {
			if (getBalance(root->rchild) == -1) {
				L(root);
			}
			else if (getBalance(root->rchild) == 1) {
				R(root->rchild);
				L(root);
			}
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);
	Node* root = NULL;
	int temp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		insert(root, temp);
	}
	printf("%d", root->data);
	return 0;
}