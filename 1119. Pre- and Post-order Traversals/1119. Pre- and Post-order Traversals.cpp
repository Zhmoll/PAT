#include <cstdio>
#include <vector>
#include <set>
using namespace std;
struct Node {
	int data;
	Node *lchild, *rchild;
};
vector<int> preOrder;
vector<int> postOrder;
vector<int> inOrder;
bool unique = true;

void inorder(Node* root) {
	if (root == NULL) return;
	inorder(root->lchild);
	inOrder.push_back(root->data);
	inorder(root->rchild);
}

Node* create(int preL, int preR, int postL, int postR) {
	if (preL > preR) return NULL;
	Node* root = new Node;
	root->data = preOrder[preL];
	set<int> a, b;
	int left = 0;
	int count = 0;
	for (int i = preL + 1, j = postL; i <= preR; i++, j++) {
		count++;
		a.insert(preOrder[i]);
		b.insert(postOrder[j]);
		if (a == b) {
			left = i - preL;
			if (left == (preR - preL)) unique = false;
			break;
		}
	}
	root->lchild = create(preL + 1, preL + left, postL, postL + left - 1);
	root->rchild = create(preL + left + 1, preR, postL + left, postR - 1);
	return root;
}

int main() {
	int N, tmp;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		preOrder.push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		postOrder.push_back(tmp);
	}
	Node* root = create(0, N - 1, 0, N - 1);
	inorder(root);

	if (unique)	printf("Yes\n");
	else printf("No\n");
	for (int i = 0; i < inOrder.size(); i++) {
		printf("%d", inOrder[i]);
		if (i != inOrder.size() - 1)printf(" ");
	}
	printf("\n");
	return 0;
}