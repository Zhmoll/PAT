#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct User {
	int user_id = -1;
	int p_score[6] = { -1,-1,-1,-1,-1,-1 };
	int score = -1;
	bool p_pass_compile[6] = { false,false,false,false,false,false };
	int p_pass_count = 0;
	int p_solved_count = 0;
	int rank = 0;
}user[10005];

bool cmp(User a, User b) {
	if (a.score > b.score) return true;
	if (a.score == b.score) {
		if (a.p_solved_count > b.p_solved_count)
			return true;
		else if (a.p_solved_count < b.p_solved_count)
			return false;
		else {
			return a.user_id < b.user_id;
		}
	}
	if (a.score < b.score) return false;
}

int main() {
	int N = 0; // 总人数
	int K = 0; // 总题目数量
	int M = 0; // 总提交数量
	int p[6] = { 0 }; // 题目对应的满分分数
	scanf("%d %d %d", &N, &K, &M);

	for (int i = 1; i <= K; i++) {
		scanf("%d", p + i);
	}

	int  user_id = 0, problem_id = 0, partial_score_obtained = 0;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &user_id, &problem_id, &partial_score_obtained);
		User* u = &user[user_id];
		u->user_id = user_id;
		if (partial_score_obtained != -1) {
			if (!u->p_pass_compile[problem_id]) {
				u->p_pass_compile[problem_id] = true;
				u->p_pass_count++;
			}
			if (partial_score_obtained > u->p_score[problem_id]) {
				u->p_score[problem_id] = partial_score_obtained;
				if (partial_score_obtained == p[problem_id]) {
					u->p_solved_count++;
				}
			}
		}
		else {
			if (u->p_score[problem_id] == -1) {
				u->p_score[problem_id] = 0;
			}
		}
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (user[i].p_pass_compile[j]) {
				if (user[i].score == -1)user[i].score = 0;
				user[i].score += user[i].p_score[j];
			}
		}
	}

	sort(user, user + N + 1, cmp);

	user[0].rank = 1;
	for (int i = 1; i <= N, user[i].score != -1; i++) {
		if (user[i - 1].score == user[i].score) {
			user[i].rank = user[i - 1].rank;
		}
		else {
			user[i].rank = i + 1;
		}
	}

	for (int i = 0; i <= N, user[i].score != -1; i++) {
		if (user[i].p_pass_count == 0)continue;
		printf("%d %05d %d ", user[i].rank, user[i].user_id, user[i].score);
		for (int j = 1; j <= K; j++) {
			if (user[i].p_score[j] != -1)
				printf("%d", user[i].p_score[j]);
			else
				printf("-");

			if (j != K)
				printf(" ");
		}
		printf("\n");
	}

	system("pause");
	return 0;
}