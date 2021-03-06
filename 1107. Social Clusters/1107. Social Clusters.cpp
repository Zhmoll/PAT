#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int hobby[1005];
int cluster[1005];

void init() {
	for (int i = 1; i <= 1000; i += 10) {
		hobby[i] = i;
		hobby[i + 1] = i + 1;
		hobby[i + 2] = i + 2;
		hobby[i + 3] = i + 3;
		hobby[i + 4] = i + 4;
		hobby[i + 5] = i + 5;
		hobby[i + 6] = i + 6;
		hobby[i + 7] = i + 7;
		hobby[i + 8] = i + 8;
		hobby[i + 9] = i + 9;
	}
}

int getRoot(int current) {
	int root = current;
	while (hobby[root] != root) root = hobby[root];
	while (hobby[current] != current) {
		int tmp = current;
		current = hobby[current];
		hobby[tmp] = root;
	}
	return root;
}

void Union(int a, int b) {
	int aroot = getRoot(a);
	int broot = getRoot(b);
	if (aroot != broot)
		hobby[broot] = aroot;
}

int main() {
	int N;
	scanf("%d", &N);
	vector<vector<int>> people(N + 1);
	init();
	for (int i = 1; i <= N; i++) {
		int K, tmp;
		scanf("%d:", &K);
		int head;
		for (int j = 0; j < K; j++) {
			scanf("%d", &tmp);
			people[i].push_back(tmp);
			if (j == 0) head = tmp;
			else Union(head, tmp);
		}
	}

	int count = 0;
	for (int i = 1; i <= N; i++) {
		int current = people[i][0];
		int root = getRoot(current);
		cluster[root]++;
		if (cluster[root] == 1) count++;
	}

	printf("%d\n", count);
	sort(cluster + 1, cluster + 1001, greater<int>());
	for (int i = 1; i <= count; i++) {
		printf("%d", cluster[i]);
		if (i != count) printf(" ");
	}

	return 0;
}