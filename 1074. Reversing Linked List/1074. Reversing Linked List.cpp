#include <cstdio>
#include <vector>
using namespace std;

struct Node {
	int address;
	int data;
	int next;
}node[100005];

int main() {
	int start, N, K;
	scanf("%d%d%d", &start, &N, &K);
	int address, data, next;
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &address, &data, &next);
		node[address].address = address;
		node[address].data = data;
		node[address].next = next;
	}
	int current = start;
	vector<Node*> stk;
	vector<Node*> q;
	while (current != -1) {
		while (stk.size() < K && current != -1) {
			stk.push_back(&node[current]);
			current = node[current].next;
		}
		if (stk.size() == K) {
			while (stk.size() > 0) {
				q.push_back(stk.back());
				stk.pop_back();
			}
		}
	}
	for (int i = 0; i < stk.size(); i++) {
		q.push_back(stk[i]);
	}
	for (int i = 0; i < q.size() - 1; i++) {
		printf("%05d %d %05d\n", q[i]->address, q[i]->data, q[i + 1]->address);
	}
	printf("%05d %d -1\n", q.back()->address, q.back()->data);
	return 0;
}