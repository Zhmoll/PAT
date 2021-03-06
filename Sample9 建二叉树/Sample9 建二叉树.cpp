#include <cstdio>
#include <vector>
using namespace std;

struct Node {
	int data;
	Node *lchild, *rchild;
};

vector<int> pre, in, post, layer;
vector<bool> layer_visited;

Node* createByPreAndIn(int preL, int preR, int inL, int inR) {
	if (preL > preR) return NULL;
	Node* current = new Node;
	current->data = pre[preL];
	int posi = -1;
	for (int i = inL; i <= inR; i++) {
		if (current->data == in[i]) {
			posi = i;
			break;
		}
	}
	int left_count = posi - inL;
	current->lchild = createByPreAndIn(preL + 1, preL + left_count, inL, posi - 1);
	current->rchild = createByPreAndIn(preL + left_count + 1, preR, posi + 1, inR);
	return current;
}

Node* createByPostAndIn(int postL, int postR, int inL, int inR) {
	if (postL > postR) return NULL;
	Node* current = new Node;
	current->data = post[postR];
	int posi = -1;
	for (int i = inL; i <= inR; i++) {
		if (current->data == in[i]) {
			posi = i;
			break;
		}
	}
	int left_count = posi - inL;
	current->lchild = createByPostAndIn(postL, postL + left_count - 1, inL, posi - 1);
	current->rchild = createByPostAndIn(postL + left_count, postR - 1, posi + 1, inR);
	return current;
}

Node* createByLayerAndIn(int inL, int inR) {
	if (inL > inR) return NULL;
	Node* current = new Node;
	int inposi = -1;
	for (int i = 0; i < layer.size(); i++) {
		if (layer_visited[i]) continue;
		for (int j = inL; j <= inR; j++) {
			if (layer[i] == in[j]) {
				layer_visited[i] = true;
				inposi = j;
				goto out;
			}
		}
	}
out:
	current->data = in[inposi];
	current->lchild = createByLayerAndIn(inL, inposi - 1);
	current->rchild = createByLayerAndIn(inposi + 1, inR);
	return current;
}

int main() {
	int N, tmp;
	scanf("%d", &N);
	layer_visited.resize(N, false);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		pre.push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		in.push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		post.push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		layer.push_back(tmp);
	}
	Node* root1 = createByPreAndIn(0, N - 1, 0, N - 1);
	Node* root2 = createByPostAndIn(0, N - 1, 0, N - 1);
	Node* root3 = createByLayerAndIn(0, N - 1);
	return 0;
}