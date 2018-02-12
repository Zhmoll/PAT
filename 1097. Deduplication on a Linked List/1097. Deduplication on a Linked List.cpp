#include <cstdio>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

struct node {
	int address;
	int key;
	int next;
}list[100005];

int main() {
	int head, N;
	scanf("%d %d", &head, &N);

	int tmp_add, tmp_key, tmp_next;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &tmp_add, &tmp_key, &tmp_next);
		list[tmp_add].address = tmp_add;
		list[tmp_add].key = tmp_key;
		list[tmp_add].next = tmp_next;
	}

	set<int> present;
	vector<int> q, remove;
	for (int i = head; i != -1; i=list[i].next) {
		int Key = abs(list[i].key);
		if (present.find(Key) != present.end()) {
			// 已经出现过了
			remove.push_back(i);
		}
		else {
			present.insert(Key);
			q.push_back(i);
		}
	}

	if (!q.empty()) {
		for (vector<int>::iterator it = q.begin(); it != q.end(); it++) {
			if (it != q.begin())
				printf("%05d\n", *it);
			printf("%05d %d ", *it, list[*it].key);
		}
		printf("-1\n");
	}

	if (!remove.empty()) {
		for (vector<int>::iterator it = remove.begin(); it != remove.end(); it++) {
			if (it != remove.begin())
				printf("%05d\n", *it);
			printf("%05d %d ", *it, list[*it].key);
		}
		printf("-1\n");
	}

	return 0;
}