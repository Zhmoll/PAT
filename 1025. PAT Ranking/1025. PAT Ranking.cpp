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
	else if (a.loc != b.loc) return a.loc < b.loc;
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
		int temp_rankl = 1;
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
	printf("%d\n", testee.size());
	int rank = 1;
	for (int i = 0; i < testee.size(); i++) {
		if (i != 0 && testee[i].score == testee[i - 1].score) {
			testee[i].rank = testee[i - 1].rank;
		}
		else {
			testee[i].rank = i + 1;
		}
		printf("%s %d %d %d\n", testee[i].id, testee[i].rank, testee[i].loc, testee[i].local_rank);
	}
	return 0;
}