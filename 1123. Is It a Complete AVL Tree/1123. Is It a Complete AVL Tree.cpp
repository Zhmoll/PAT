#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int data;
	Node *lchild, *rchild;
	int height;
};

Node* newNode(int data) {
	Node* root = new Node;
	root->data = data;
	root->lchild = root->rchild = NULL;
	root->height = 1;
	return root;
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

bool flag = false, complete = true;
int printcount = 0;
int N;

void levelOrder(Node* root) {
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node* current = q.front();
		q.pop();
		if (current == NULL) {
			flag = true;
			continue;
		}
		if (flag) {
			complete = false;
		}
		printf("%d", current->data);
		printcount++;
		if (printcount != N) printf(" ");
		q.push(current->lchild);
		q.push(current->rchild);
	}
}

int main() {
	scanf("%d", &N);
	int temp;
	Node* root = NULL;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		insert(root, temp);
	}
	levelOrder(root);
	if (complete) printf("\nYES");
	else printf("\nNO");
	return 0;
}