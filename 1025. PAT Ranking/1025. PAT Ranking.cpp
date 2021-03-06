#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct record {
	char id[20];
	int score;
	int rank;
	int loc;
	int local_rank;
};

vector<record> testee;

bool cmp(record &a, record &b) {
	if (a.score != b.score) return a.score > b.score;
	else return strcmp(a.id, b.id) < 0;
}

int main() {
	int N;
	scanf("%d", &N);
	int num = 0;
	for (int i = 0; i < N; i++) {
		int K;
		scanf("%d", &K);
		for (int j = 0; j < K; j++) {
			record a;
			scanf("%s %d", &a.id, &a.score);
			a.loc = i + 1;
			testee.push_back(a);
		}
		sort(testee.begin() + num, testee.end(), cmp);
		testee[num].local_rank = 1;
		for (int j = num + 1; j < num + K; j++) {
			if (testee[j].score == testee[j - 1].score) {
				testee[j].local_rank = testee[j - 1].local_rank;
			}
			else {
				testee[j].local_rank = j - num + 1;
			}
		}
		num += K;
	}
	sort(testee.begin(), testee.end(), cmp);

	testee[0].rank = 1;
	for (int i = 1; i < testee.size(); i++) {
		if (testee[i].score == testee[i - 1].score) {
			testee[i].rank = testee[i - 1].rank;
		}
		else {
			testee[i].rank = i + 1;
		}
	}

	printf("%d\n", testee.size());
	for (int i = 0; i < testee.size(); i++) {
		printf("%s %d %d %d\n", testee[i].id, testee[i].rank, testee[i].loc, testee[i].local_rank);
	}
	return 0;
}