#include <cstdio>
#include <vector>
using namespace std;
struct Node {
	int address;
	int data;
	int next; // NULL 是 -1
}node[100005];

int main() {
	int head, N, K;
	scanf("%d%d%d", &head, &N, &K);
	int address, data, next;
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &address, &data, &next);
		node[address].address = address;
		node[address].data = data;
		node[address].next = next;
	}

	vector<Node> q;
	int current = head;
	while (current != -1) {
		if (node[current].data < 0) {
			q.push_back(node[current]);
		}
		current = node[current].next;
	}
	current = head;
	while (current != -1) {
		if (node[current].data >= 0 && node[current].data <= K) {
			q.push_back(node[current]);
		}
		current = node[current].next;
	}
	current = head;
	while (current != -1) {
		if (node[current].data > K) {
			q.push_back(node[current]);
		}
		current = node[current].next;
	}

	int i;
	for (i = 0; i < q.size()-1; i++) {
		printf("%05d %d %05d\n", q[i].address, q[i].data, q[i + 1].address);
	}
	printf("%05d %d -1", q[i].address, q[i].data);

	return 0;
}