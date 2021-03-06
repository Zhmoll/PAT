#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
struct Node {
	int data;
	bool red;
	Node *lchild, *rchild;
};

void insert(Node* &root, int data) {
	if (root == NULL) {
		root = new Node;
		root->data = abs(data);
		root->red = data < 0 ? true : false;
		root->lchild = root->rchild = NULL;
		return;
	}

	if (abs(data) < root->data)
		insert(root->lchild, data);
	else
		insert(root->rchild, data);
}

bool cmp(Node &a, Node &b) {
	return a.data < b.data;
}

bool redblack = true;
int record, tmp_record;

void DFS(Node* root) {
	if (root == NULL) {
		if (record == -1) record = tmp_record;
		else if (record != tmp_record) {
			redblack = false;
		}
		return;
	}
	if (!root->red) tmp_record++;
	DFS(root->lchild);
	DFS(root->rchild);
	if (!root->red) tmp_record--;
}

bool checkredblack(Node* root) {
	if (root->red) return false;
	queue<Node*> q;
	q.push(root);
	redblack = true;
	while (!q.empty()) {
		Node* current = q.front();
		q.pop();
		if (current == NULL) continue;
		if (current->red) {
			if (current->lchild != NULL && current->lchild->red) redblack = false;
			if (current->rchild != NULL && current->rchild->red) redblack = false;
		}
		record = -1;
		tmp_record = 0;
		DFS(current);
		q.push(current->lchild);
		q.push(current->rchild);
	}
	return redblack;
}

int main() {
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int N, tmp;
		scanf("%d", &N);
		Node* root = NULL;
		for (int i = 0; i < N; i++) {
			scanf("%d", &tmp);
			insert(root, tmp);
		}

		if (checkredblack(root)) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}