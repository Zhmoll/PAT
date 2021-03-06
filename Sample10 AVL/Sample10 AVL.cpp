#include <cstdio>
#include <algorithm>
using namespace std;

struct Node {
	int data;
	int height;
	Node *lchild, *rchild;
};

Node* newNode(int data) {
	Node* current = new Node;
	current->data = data;
	current->height = 1;
	current->lchild = current->rchild = NULL;
	return current;
}

int getHeight(Node* root) {
	if (root == NULL) return 0;
	else return root->height;
}

int getBalance(Node* root) {
	if (root == NULL) return 0;
	else return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(Node* root) {
	if (root == NULL) return;
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

void search(Node* root, int data) {
	if (root == NULL) {
		printf("没找到");
		return;
	}

	if (data == root->data) {
		printf("找到了");
	}
	else if (data < root->data) {
		search(root->lchild, data);
	}
	else {
		search(root->rchild, data);
	}
}

void L(Node* &root) {
	Node* tmp = root->rchild;
	root->rchild = tmp->lchild;
	tmp->lchild = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}

void R(Node* &root) {
	Node* tmp = root->lchild;
	root->lchild = tmp->rchild;
	tmp->rchild = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
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

	return 0;
}