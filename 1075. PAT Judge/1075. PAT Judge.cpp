// 20点00分
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct user {
	int id;
	vector<int> score;
	vector<bool> is_submitted;
	int total;
	int perfect;
	bool valid;
	user() {
		valid = false;
	}
};

user input[10005];
int total_score[6];

bool cmp(user &a, user &b) {
	if (!a.valid) return false;
	if (!b.valid) return true;
	if (a.total != b.total) return a.total > b.total;
	else if (a.perfect != b.perfect) return a.perfect > b.perfect;
	else return a.id < b.id;
}

int main() {
	int N, K, M;
	scanf("%d%d%d", &N, &K, &M);
	for (int i = 1; i <= K; i++) {
		scanf("%d", &total_score[i]);
	}
	int id, problem_id, score;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &id, &problem_id, &score);
		if (input[id].score.size() == 0) {
			input[id].id = id;
			input[id].score.resize(K + 1, 0);
			input[id].is_submitted.resize(K + 1, false);
		}
		input[id].is_submitted[problem_id] = true;

		if (score == -1) continue;
		input[id].valid = true;

		if (score > input[id].score[problem_id]) {
			input[id].score[problem_id] = score;
		}

		input[id].perfect = 0;
		input[id].total = 0;
		for (int j = 1; j <= K; j++) {
			if (input[id].score[j] == total_score[j]) input[id].perfect++;
			if (input[id].score[j] >= 0)input[id].total += input[id].score[j];
		}
	}
	sort(input, input + 10005, cmp);

	int last_rank = 0;
	int last_score = -1;
	for (int i = 0; i < 10005; i++) {
		if (!input[i].valid) continue;
		if (input[i].total == last_score) {
			printf("%d %05d %d", last_rank, input[i].id, input[i].total);
		}
		else {
			printf("%d %05d %d", i + 1, input[i].id, input[i].total);
			last_rank = i + 1;
			last_score = input[i].total;
		}
		for (int j = 1; j <= K; j++) {
			if (input[i].is_submitted[j])
				printf(" %d", input[i].score[j]);
			else
				printf(" -");
		}
		printf("\n");
	}
	return 0;
}