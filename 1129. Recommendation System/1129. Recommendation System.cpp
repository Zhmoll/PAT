#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Item {
	int id;
	int count;
};

bool cmp(Item &a, Item &b) {
	if (a.count != b.count) return a.count > b.count;
	else return a.id < b.id;
}

bool cmp_re(Item &a, Item &b) {
	return a.id < b.id;
}

int main() {
	int N, K; // N, the total number of queries; K, the maximum number of recommendations the system must show to the user.
	scanf("%d%d", &N, &K);
	vector<Item> item(50000 + 1);

	for (int i = 1; i <= 50000; i++) {
		item[i].id = i;
		item[i].count = 0;
		//item[i + 1].id = i + 1;
		//item[i + 1].count = 0;
		//item[i + 2].id = i + 2;
		//item[i + 2].count = 0;
		//item[i + 3].id = i + 3;
		//item[i + 3].count = 0;
		//item[i + 4].id = i + 4;
		//item[i + 4].count = 0;
		//item[i + 5].id = i + 5;
		//item[i + 5].count = 0;
		//item[i + 6].id = i + 6;
		//item[i + 6].count = 0;
		//item[i + 7].id = i + 7;
		//item[i + 7].count = 0;
		//item[i + 8].id = i + 8;
		//item[i + 8].count = 0;
		//item[i + 9].id = i + 9;
		//item[i + 9].count = 0;
	}

	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		if (i != 0) {
			printf("%d:", tmp);
			sort(item.begin() + 1, item.end(), cmp);
			int len = item.size() < K ? item.size() : K;
			for (int j = 1; j <= len; j++) {
				if (item[j].count == 0) break;
				else {
					printf(" %d", item[j].id);
				}
			}
			printf("\n");
		}
		sort(item.begin() + 1, item.end(), cmp_re);
		item[tmp].count++;
	}
	return 0;
}