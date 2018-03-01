#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> node;
vector<int> input;
int N, current = 0;

void inorder(int root) {
	if (root <= N) {
		inorder(2 * root);
		node[root] = input[current++];
		inorder(2 * root + 1);
	}
}

int main() {
	scanf("%d", &N);
	input.resize(N);
	node.resize(N + 1);
	for (int i = 0; i < N; i++)
		scanf("%d", &input[i]);
	sort(input.begin(), input.end());

	inorder(1);

	for (int i = 1; i <= N; i++) {
		printf("%d", node[i]);
		if (i != N) printf(" ");
	}
	return 0;
}