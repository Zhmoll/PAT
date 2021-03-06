#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 10010;
int father[maxn];

void init() {
	for (int i = 0; i < maxn; i++) {
		father[i] = i;
	}
}

int findFather(int x) {
	int root = x;
	while (root != father[root]) root = father[root];
	while (x != father[x]) {
		int tmp = father[x];
		father[x] = root;
		x = tmp;
	}
	return a;
}

void Union(int a, int b) {
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB) {
		father[faB] = faA;
	}
}

int main() {

	return 0;
}