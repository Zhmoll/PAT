#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

vector<int> inorder;
vector<int> preorder;
vector<int> postorder;

struct Node {
	int data;
	Node* lchild;
	Node* rchild;
};

Node* create(int preL, int preR, int inL, int inR) {
	if (preL > preR) {
		return NULL;
	}

	Node* root = new Node;
	root->data = preorder[preL];
	int posi = -1;
	for (int i = inL; i <= inR; i++) {
		if (inorder[i] == root->data) {
			posi = i;
			break;
		}
	}

	int leftLen = posi - inL;
	root->lchild = create(preL+1, preL + leftLen, inL, posi - 1);
	root->rchild = create(preL + leftLen + 1, preR, posi + 1, inR);
	return root;
}

void postOrder(Node* root) {
	if (root == NULL) return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	postorder.push_back(root->data);
}

int main() {
	int N, num;
	scanf("%d", &N);
	stack<int> node;
	
	string action;
	for (int i = 0; i < 2 * N; i++) {
		cin >> action;
		if (action == "Push") {
			cin >> num;
			node.push(num);
			preorder.push_back(num);
		}
		else if (action == "Pop") {
			inorder.push_back(node.top());
			node.pop();
		}
	}

	Node* root = create(0, preorder.size() - 1, 0, inorder.size() - 1);
	postOrder(root);

	for (int i = 0; i < N; i++) {
		cout << postorder[i];
		if (i != N - 1) cout << " ";
	}

	return 0;
}