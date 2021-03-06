#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

vector<int> postOrder;
vector<int> inOrder;

Node* create(int postL, int postR, int inL, int inR) {
	if (postL > postR) return NULL;
	int current = postR;
	Node* root = new Node;
	root->data = postOrder[current];
	int posi;
	for (int i = inL; i <= inR; i++) {
		if (root->data == inOrder[i]) {
			posi = i;
			break;
		}
	}
	int left = posi - inL;
	root->left = create(postL, postL + left - 1, inL, posi - 1);
	root->right = create(postL + left, postR - 1, posi + 1, inR);
	return root;
}

int main() {
	int N;
	scanf("%d", &N);
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		inOrder.push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		postOrder.push_back(tmp);
	}
	Node* root = create(0, N - 1, 0, N - 1);

	vector<Node*> leftStack;
	vector<Node*> rightStack;
	bool isLeft = true;
	leftStack.push_back(root);
	int count=0;
	while (leftStack.size()!=0 || rightStack.size() != 0) {
		if (isLeft) {
			int len = leftStack.size();
			for (int i = 0; i < len; i++) {
				Node* current = leftStack.back();
				leftStack.pop_back();
				printf("%d", current->data);
				count++;
				if (count != N) printf(" ");
				if (current->right != NULL) rightStack.push_back(current->right);
				if (current->left != NULL) rightStack.push_back(current->left);
			}
			isLeft = false;
		}
		else {
			int len = rightStack.size();
			for (int i = 0; i < len; i++) {
				Node* current = rightStack.back();
				rightStack.pop_back();
				printf("%d", current->data);
				count++;
				if (count != N) printf(" ");
				if (current->left != NULL) leftStack.push_back(current->left);
				if (current->right != NULL) leftStack.push_back(current->right);
			}
			isLeft = true;
		}
	}
	return 0;
}