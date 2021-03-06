#include <cstdio>
#include <set>
#include <vector>
using namespace std;

struct node {
	int value, count;
	node(int value, int count):value(value),count(count) {}
	bool operator<(const node &a) const {
		return (count != a.count) ? count > a.count:value < a.value;
	}
};

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	set<node> item;
	vector<int> count(N + 1);
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		if (i != 0) {
			printf("%d:", tmp);
			set<node>::iterator it = item.begin();
			for (int i = 0; i < K && it != item.end(); i++, it++) {
				printf(" %d", (*it).value);
			}
			printf("\n");
		}
		// 找到要更新的删掉
		set<node>::iterator it = item.find(node(tmp, count[tmp]));
		if(it!=item.end())
			item.erase(it);
		count[tmp]++;
		item.insert(node(tmp, count[tmp]));
	}

	return 0;
}