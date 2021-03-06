#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
queue<int> invert_q;
struct Node {
	int left, right;
};

void inorder(vector<Node> &node, int i) {
	if (i == -1) return;
	inorder(node, node[i].right);
	invert_q.push(i);
	inorder(node, node[i].left);
}

int main() {
	int N, root = -1;
	scanf("%d\n", &N);
	vector<Node> node(N);
	vector<int> hash(N);
	for (int i = 0; i < N; i++) {
		char tmp_l, tmp_r;
		scanf("%c %c", &tmp_l, &tmp_r);
		getchar();
		if (tmp_l != '-') {
			node[i].left = tmp_l - '0';
			hash[tmp_l - '0']++;
		}
		else
			node[i].left = -1;

		if (tmp_r != '-') {
			node[i].right = tmp_r - '0';
			hash[tmp_r - '0']++;
		}
		else
			node[i].right = -1;
	}

	for (int i = 0; i < N; i++) {
		if (hash[i] == 0) {
			root = i;
			break;
		}
	}

	queue<int> level_q;
	int current = root;
	level_q.push(current);
	while (level_q.size() != 0) {
		current = level_q.front();
		printf("%d", current);
		level_q.pop();
		if (node[current].right != -1) {
			level_q.push(node[current].right);
		}
		if (node[current].left != -1) {
			level_q.push(node[current].left);
		}
		if (level_q.size() != 0) printf(" ");
	}
	printf("\n");
	inorder(node, root);
	while (invert_q.size() != 0) {
		printf("%d", invert_q.front());
		invert_q.pop();
		if (invert_q.size() != 0) printf(" ");
	}
	return 0;
}