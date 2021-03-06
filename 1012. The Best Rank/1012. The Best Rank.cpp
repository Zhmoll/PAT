#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const char shunxu[4] = { 'C','M','E','A' };

struct stu {
	int id;
	int score[4];
	int rank[4];
};

vector<stu> result;
int now;

bool cmp(stu &a, stu &b) {
	return a.score[now] > b.score[now];
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		stu a;
		scanf("%d %d %d %d", &a.id, &a.score[0], &a.score[1], &a.score[2]);
		a.score[3] = a.score[0] + a.score[1] + a.score[2];
		result.push_back(a);
	}

	for (now = 0; now < 4; now++) {
		sort(result.begin(), result.end(), cmp);
		result[0].rank[now] = 1;
		for (int i = 1; i < result.size(); i++) {
			if (result[i].score[now] == result[i - 1].score[now]) {
				result[i].rank[now] = result[i - 1].rank[now];
			}
			else {
				result[i].rank[now] = i + 1;
			}
		}
	}

	int q;
	for (int i = 0; i < M; i++) {
		scanf("%d", &q);
		int posi = -1;
		for (int i = 0; i < result.size(); i++) {
			if (result[i].id == q) {
				posi = i;
				break;
			}
		}
		if (posi == -1) printf("N/A\n");
		else {
			int best = 3;
			int rank = result[posi].rank[3];
			if (result[posi].rank[0] < rank) {
				rank = result[posi].rank[0];
				best = 0;
			}
			if (result[posi].rank[1] < rank) {
				rank = result[posi].rank[1];
				best = 1;
			}
			if (result[posi].rank[2] < rank) {
				rank = result[posi].rank[2];
				best = 2;
			}
			printf("%d %c\n", rank, shunxu[best]);
		}
	}
	return 0;
}