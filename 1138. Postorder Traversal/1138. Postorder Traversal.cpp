#include <cstdio>

int pre[50005] = { 0 };
int in[50005] = { 0 };

struct node {
	int key;
	node* lchild;
	node* rchild;
};

node* create(int preL, int preR, int inL, int inR) {
	if (preL > preR) return NULL;
	node* current = new node;
	current->key = pre[preL];
	int i;
	for (i = inL; i <= inR; i++) {
		if (in[i] == pre[preL]) {
			break;
		}
	}
	int leftLen = i - inL;
	current->lchild = create(preL + 1, preL + leftLen, inL, i - 1);
	current->rchild = create(preL + leftLen + 1, preR, i + 1, inR);
	return current;
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", pre + i);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", in + i);
	}
	node* root = create(0, N - 1, 0, N - 1);
	node* current = root;
	while (1) {
		while (current->lchild != NULL) {
			current = current->lchild;
		}
		if (current->rchild != NULL) {
			current = current->rchild;
		}
		else {
			break;
		}
	}
	printf("%d", current->key);
	return 0;
}