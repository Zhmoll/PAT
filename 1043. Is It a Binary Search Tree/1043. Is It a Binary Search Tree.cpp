#include <cstdio>
#include <vector>
using namespace std;

struct Node {
	int data;
	Node *lchild, *rchild;
};

void insert(Node* &root, int x) {
	if (root == NULL) {
		root = new Node;
		root->data = x;
		root->lchild = root->rchild = NULL;
		return;
	}

	if (x < root->data) insert(root->lchild, x);
	else insert(root->rchild, x);
}

void insertMirror(Node* &root, int x) {
	if (root == NULL) {
		root = new Node;
		root->data = x;
		root->lchild = root->rchild = NULL;
		return;
	}

	if (x >= root->data) insertMirror(root->lchild, x);
	else insertMirror(root->rchild, x);
}

void preOrder(Node* root, vector<int> &pre) {
	if (root == NULL) return;
	pre.push_back(root->data);
	preOrder(root->lchild, pre);
	preOrder(root->rchild, pre);
}

void postOrder(Node* root, vector<int> &post) {
	if (root == NULL) return;
	postOrder(root->lchild, post);
	postOrder(root->rchild, post);
	post.push_back(root->data);
}

int main() {
	int N, tmp;
	scanf("%d", &N);
	vector<int> vi;
	Node *root1 = NULL, *root2 = NULL;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		vi.push_back(tmp);
		insert(root1, tmp);
		insertMirror(root2, tmp);
	}
	vector<int> pre1, pre2, post;
	preOrder(root1, pre1);
	preOrder(root2, pre2);
	if (vi == pre1) {
		printf("YES\n");
		postOrder(root1, post);
		for (int i = 0; i < post.size(); i++) {
			printf("%d", post[i]);
			if (i != post.size() - 1) printf(" ");
			else printf("\n");
		}
	}
	else if (vi == pre2) {
		printf("YES\n");
		postOrder(root2, post);
		for (int i = 0; i < post.size(); i++) {
			printf("%d", post[i]);
			if (i != post.size() - 1) printf(" ");
			else printf("\n");
		}
	}
	else {
		printf("NO\n");
	}
	return 0;
}