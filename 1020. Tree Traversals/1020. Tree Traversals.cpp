#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int key;
	Node* lchild;
	Node* rchild;
};

Node* createByPostOrderAndInOrder(vector<int> &post, vector<int> &in, int postL, int postR, int inL, int inR) {
	if (postL > postR) {
		return NULL;
	}

	Node* current = new Node;
	current->key = post[postR];
	int currentIn = -1;
	for (int i = inL; i <= inR; i++) {
		if (current->key == in[i]) {
			currentIn = i;
			break;
		}
	}

	int leftChildCount = currentIn - inL;

	current->lchild = createByPostOrderAndInOrder(post, in, postL, postL + leftChildCount - 1, inL, currentIn - 1);
	current->rchild = createByPostOrderAndInOrder(post, in, postL + leftChildCount, postR - 1, currentIn + 1, inR);
	return current;
}

int main() {
	int N;
	scanf("%d", &N);
	vector<int> post(N);
	vector<int> in(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &post[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &in[i]);
	}

	Node* root = createByPostOrderAndInOrder(post, in, 0, N - 1, 0, N - 1);

	queue<Node*> q;
	q.push(root);
	while (1) {
		Node* current = q.front();
		q.pop();
		if (current->lchild != NULL) q.push(current->lchild);
		if (current->rchild != NULL) q.push(current->rchild);
		printf("%d", current->key);
		if (q.size() != 0) printf(" ");
		else break;
	}

	return 0;
}