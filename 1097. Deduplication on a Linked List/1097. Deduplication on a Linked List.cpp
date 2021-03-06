#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int address;
	int data;
	int next;
}node[100005];

bool existed[10005] = { false };

int main() {
	int start, N;
	scanf("%d%d", &start, &N);
	int address, data, next;
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &address, &data, &next);
		node[address].address = address;
		node[address].data = data;
		node[address].next = next;
	}
	int current = start;
	vector<Node*> q;
	vector<Node*> removed;
	while (current != -1) {
		if (existed[abs(node[current].data)]) {
			removed.push_back(&node[current]);
		}
		else {
			q.push_back(&node[current]);
			existed[abs(node[current].data)] = true;
		}
		current = node[current].next;
	}
	for (int i = 0; i < q.size(); i++) {
		if (i < q.size() - 1) {
			printf("%05d %d %05d\n", q[i]->address, q[i]->data, q[i + 1]->address);
		}
		else {
			printf("%05d %d -1\n", q[i]->address, q[i]->data);
		}
	}
	for (int i = 0; i < removed.size(); i++) {
		if (i < removed.size() - 1) {
			printf("%05d %d %05d\n", removed[i]->address, removed[i]->data, removed[i + 1]->address);
		}
		else {
			printf("%05d %d -1\n", removed[i]->address, removed[i]->data);
		}
	}
	return 0;
}