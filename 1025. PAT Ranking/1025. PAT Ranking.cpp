#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct testee {
	char reg[14]; // 13-digit number
	int loc; // 0<N<=100
	int score;
	int loc_rank;
	int final_rank;
	testee() {
		loc_rank = 0;
		final_rank = 0;
	}
}item[30005];

int total = 0;

bool cmp(testee a, testee b) {
	if (a.score > b.score) {
		return true;
	}
	else if (a.score == b.score) {
		return strcmp(a.reg, b.reg) < 0;
	}
	return false;
}

int main() {
	int N = 0; // the number of test locations
	int K[305] = { 0 }; // the number of testees

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &K[i]); // i is the location_number, K[i] is the sum of one location testees
		for (int j = 0; j < K[i]; j++) {
			scanf("%s %d", &item[total].reg, &item[total].score);
			item[total].loc = i + 1;
			total++;
		}
		// local_rank
		sort(item + total - K[i], item + total, cmp);
		item[total - K[i]].loc_rank = 1;
		for (int j = total - K[i] + 1; j < total; j++) {
			if (item[j].score == item[j - 1].score) {
				item[j].loc_rank = item[j - 1].loc_rank;
			}
			else {
				item[j].loc_rank = j - (total - K[i]) + 1;
			}
		}
	}

	sort(item, item + total, cmp);
	item[0].final_rank = 1;
	for (int i = 1; i < total; i++) {
		if (item[i].score == item[i - 1].score) {
			item[i].final_rank = item[i - 1].final_rank;
		}
		else {
			item[i].final_rank = i + 1;
		}
	}

	printf("%d\n", total);
	for (int i = 0; i < total; i++) {
		printf("%s %d %d %d\n", item[i].reg, item[i].final_rank, item[i].loc, item[i].loc_rank);
	}

	system("pause");
	return 0;
}