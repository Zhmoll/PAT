#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int data;
}node[1005];

vector<int> input;
int N;
int posi = 0;

void inOrder(int current) {
	if (current > N) {
		return;
	}

	inOrder(current * 2);
	node[current].data = input[posi++];
	inOrder(current * 2 + 1);
}

int main() {
	scanf("%d", &N);
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		input.push_back(tmp);
	}
	sort(input.begin(), input.end());
	inOrder(1);
	for (int i = 1; i <= N; i++) {
		printf("%d", node[i]);
		if (i != N) printf(" ");
	}
	return 0;
}