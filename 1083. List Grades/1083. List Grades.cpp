#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct score {
	char name[16];
	char ID[16];
	int grade;
};

bool cmp(score a, score b) {
	return a.grade > b.grade;
}

int main() {
	int N;
	scanf("%d", &N);
	vector<score> record(N);
	for (int i = 0; i < N; i++) {
		scanf("%s %s %d", record[i].name, record[i].ID, &record[i].grade);
	}

	sort(record.begin(), record.end(), cmp);
	
	int min, max;
	scanf("%d %d", &min, &max);
	score score_min = { "","",min };
	score score_max = { "","",max };
	vector<score>::iterator lo = lower_bound(record.begin(), record.end(), score_max, cmp);
	// lower_bound：key 的第一个
	vector<score>::iterator hi = upper_bound(record.begin(), record.end(), score_min, cmp);
	// upper_bound：key 的最后一个加一

	if (lo == hi) {
		printf("NONE");
	}
	for (; lo != hi; lo++) {
		printf("%s %s\n", lo->name, lo->ID);
	}

	// 线性查找也ac
	//queue<score> stk;
	//for (int i = 0; i < N; i++) {
	//	if (min <= record[i].grade&&record[i].grade <= max) {
	//		stk.push(record[i]);
	//	}
	//}

	//if (stk.size() == 0) {
	//	printf("NONE");
	//}
	//else {
	//	while (stk.size() != 0) {
	//		printf("%s %s\n", stk.front().name, stk.front().ID);
	//		stk.pop();
	//	}
	//}

	return 0;
}