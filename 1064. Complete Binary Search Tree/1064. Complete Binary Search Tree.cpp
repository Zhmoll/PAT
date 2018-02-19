#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int data;
	Node* lchild;
	Node* rchild;
};

void insert(Node* &root, int data) {
	if (root == NULL) {
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

int main() {
	int N;
	scanf("%", &N);
	int tmp;
	vector<int> q;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		q.push_back(tmp);
	}
	sort(q.begin(), q.end());
	Node* root = NULL;
	while (1) {
		
	}
	return 0;
}