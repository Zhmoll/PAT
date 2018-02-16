#include <cstdio>
#include <vector>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

void insert(Node* &root, int data) {
	if (root == NULL) {
		root = new Node;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		return;
	}
	if (data < root->data) insert(root->left, data);
	else insert(root->right, data);
}

void preOrder(Node* root, vector<int> &vi) {
	if (root == NULL) return;
	vi.push_back(root->data);
	preOrder(root->left, vi);
	preOrder(root->right, vi);
}

void preOrderM(Node* root, vector<int> &vi) {
	if (root == NULL) return;
	vi.push_back(root->data);
	preOrderM(root->right, vi);
	preOrderM(root->left, vi);
}

void postOrder(Node* root, vector<int> &vi) {
	if (root == NULL) return;
	postOrder(root->left, vi);
	postOrder(root->right, vi);
	vi.push_back(root->data);
}

void postOrderM(Node* root, vector<int> &vi) {
	if (root == NULL) return;
	postOrder(root->right, vi);
	postOrder(root->left, vi);
	vi.push_back(root->data);
}

int main() {
	int N, tmp;
	scanf("%d", &N);
	Node* root = NULL;
	vector<int> origin, pre, preM, post, postM;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		insert(root, tmp);
		origin.push_back(tmp);
	}

	preOrder(root, pre);
	preOrderM(root, preM);
	postOrder(root, post);
	postOrderM(root, postM);
	if (origin == pre) {
		printf("YES\n");
		for (int i = 0; i < post.size(); i++) {
			printf("%d", post[i]);
			if (i != post.size() - 1) printf(" ");
		}
	}
	else if (origin == preM) {
		printf("YES\n");
		for (int i = 0; i < postM.size(); i++) {
			printf("%d", postM[i]);
			if (i != postM.size() - 1) printf(" ");
		}
	}
	else {
		printf("NO");
	}
	return 0;
}