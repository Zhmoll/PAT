#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct applicant {
	int id;
	int exam, interview;
	double finalgrade;
	vector<int> prefer;
	int rank;
};

bool cmp(applicant &a, applicant &b) {
	if (a.finalgrade != b.finalgrade) return a.finalgrade > b.finalgrade;
	else return a.exam > b.exam;
}

int main() {
	int N, M, K, tmp;
	scanf("%d%d%d", &N, &M, &K);
	vector<int> quota(M);
	vector<int> school_last_rank(M);
	vector<vector<int>> school(M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &quota[i]);
	}
	int exam, interview;
	vector<applicant> input;
	for (int i = 0; i < N; i++) {
		applicant a;
		a.id = i;
		scanf("%d%d", &a.exam, &a.interview);
		a.finalgrade = (a.exam + a.interview) / 2;
		for (int j = 0; j < K; j++) {
			scanf("%d", &tmp);
			a.prefer.push_back(tmp);
		}
		input.push_back(a);
	}
	sort(input.begin(), input.end(), cmp);

	// proceed the rank
	input[0].rank = 1;
	for (int i = 1; i < input.size(); i++) {
		if (input[i].finalgrade != input[i - 1].finalgrade) {
			input[i].rank = input[i - 1].rank + 1;
		}
		else if (input[i].finalgrade == input[i - 1].finalgrade && input[i].exam != input[i - 1].exam) {
			input[i].rank = input[i - 1].rank + 1;
		}
		else if (input[i].finalgrade == input[i - 1].finalgrade && input[i].exam == input[i - 1].exam) {
			input[i].rank = input[i - 1].rank;
		}
	}

	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < input[i].prefer.size(); j++) {
			int prefer = input[i].prefer[j];
			int rank = input[i].rank;
			int id = input[i].id;
			if (quota[prefer] > 0 || school_last_rank[prefer] == rank) {
				school[prefer].push_back(id);
				quota[prefer]--;
				school_last_rank[prefer] = rank;
				break;
			}
		}
	}

	for (int i = 0; i < school.size(); i++) {
		if (school[i].size() == 0) printf("\n");
		else sort(school[i].begin(), school[i].end());
		for (int j = 0; j < school[i].size(); j++) {
			printf("%d", school[i][j]);
			if (j != school[i].size() - 1) printf(" ");
			else printf("\n");
		}
	}

	return 0;
}