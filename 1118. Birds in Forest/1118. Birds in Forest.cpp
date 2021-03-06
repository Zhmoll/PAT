#include <cstdio>
#include <vector>
using namespace std;
int father[10005];
bool isRoot[10005];
int getFather(int i) {
	int root = i;
	while (father[root] != root) root = father[root];
	while (father[i] != i) {
		int tmp = i;
		i = father[i];
		father[tmp] = root;
	}
	return root;
}

void Union(int a, int b) {
	int roota = getFather(a);
	int rootb = getFather(b);
	if (roota != rootb) {
		father[rootb] = roota;
		isRoot[roota] = true;
		isRoot[rootb] = false;
	}
}

void init() {
	for (int i = 1; i <= 10000; i++) {
		father[i] = i;
		isRoot[i] = false;
	}
}

int main() {
	int N, max = 0;
	scanf("%d", &N);
	vector<vector<int>> input(N);
	init();
	for (int i = 0; i < N; i++) {
		int K, tmp, head;
		scanf("%d", &K);
		for (int j = 0; j < K; j++) {
			scanf("%d", &tmp);
			if (tmp > max) max = tmp;
			input[i].push_back(tmp);
			if (j == 0) {
				head = tmp;
				if (father[head] == head)
					isRoot[head] = true;
			}
			else Union(head, tmp);
		}
	}

	int count = 0;
	for (int i = 1; i <= 10000; i++) {
		if (isRoot[i]) count++;
	}

	printf("%d %d\n", count, max);

	int Q;
	scanf("%d", &Q);
	int a, b;
	for (int i = 0; i < Q; i++) {
		scanf("%d%d", &a, &b);
		if (getFather(a) == getFather(b)) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}

	return 0;
}