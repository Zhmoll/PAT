#include <cstdio>
#include <algorithm>

using namespace std;

struct node {
	int address;
	int key;
	int next;
	bool need = false;
}list[100005];

bool cmp(node a, node b) {
	if (a.need && !b.need) return true;
	else if (!a.need && b.need) return false;
	else return a.key < b.key;
}

int main() {
	int N, head;
	scanf("%d%d", &N, &head);

	int address, key, next;
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &address, &key, &next);
		list[address].address = address;
		list[address].key = key;
		list[address].next = next;
		list[address].need = false;
	}

	int count = 0;
	for (int i = head; i != -1; i = list[i].next) {
		list[i].need = true;
		count++;
	}

	sort(list, list + 100005, cmp);

	for (int i = 0; i < count; i++) {
		list[i].next = list[i + 1].address;
	}
	list[count - 1].next = -1;

	if (list[0].need) {
		printf("%d %05d\n", count, list[0].address);
		for (int i = 0; i < count - 1; i++) {
			printf("%05d %d %05d\n", list[i].address, list[i].key, list[i].next);
		}
		printf("%05d %d -1\n", list[count - 1].address, list[count - 1].key);
	}
	else
		printf("%d -1\n", count);

	return 0;
}