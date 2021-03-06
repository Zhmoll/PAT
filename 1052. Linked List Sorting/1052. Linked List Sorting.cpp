#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
	int address;
	int data;
	int next;
}node[100005];

bool cmp(int a, int b) {
	return node[a].data < node[b].data;
}
vector<int> vi;
int main() {
	int N, start;
	scanf("%d %d", &N, &start);
	int address, next, data;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &address, &data, &next);
		node[address].address = address;
		node[address].data = data;
		node[address].next = next;
	}
	int current = start;
	while (current != -1) {
		vi.push_back(current);
		current = node[current].next;
	}
	if (vi.empty()) {
		printf("0 -1\n");
		return 0;
	}
	sort(vi.begin(), vi.end(), cmp);
	printf("%d %05d\n", vi.size(), node[vi[0]].address);
	for (int i = 0; i < vi.size() - 1; i++) {
		printf("%05d %d %05d\n", node[vi[i]].address, node[vi[i]].data, node[vi[i + 1]].address);
	}
	printf("%05d %d -1\n", node[vi.back()].address, node[vi.back()].data);
	return 0;
}