// 20点51分
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct applicant {
	int id;
	int exam, interview;
	int grade;
	int rank;
	vector<int> choice;
	applicant(int id, int exam, int interview) :id(id), exam(exam), interview(interview) {
		grade = exam + interview;
	}
};

bool cmp(applicant &a, applicant &b) {
	if (a.grade != b.grade) return a.grade > b.grade;
	else return a.exam > b.exam;
}

vector<applicant> input;
vector<int> quota;
vector<int> last_rank;
vector<set<int>> admission;

int main() {
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	quota.resize(M);
	last_rank.resize(M);
	admission.resize(M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &quota[i]);
	}
	int exam, interview, tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &exam, &interview);
		input.push_back(applicant(i, exam, interview));
		for (int j = 0; j < K; j++) {
			scanf("%d", &tmp);
			input[i].choice.push_back(tmp);
		}
	}
	sort(input.begin(), input.end(), cmp);

	input[0].rank = 1;
	for (int i = 1; i < input.size(); i++) {
		if (input[i].grade == input[i - 1].grade) {
			if (input[i].exam != input[i - 1].exam)
				input[i].rank = i + 1;
			else
				input[i].rank = input[i - 1].rank;
		}
		else {
			input[i].rank = i + 1;
		}
	}

	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < input[i].choice.size(); j++) {
			if (quota[input[i].choice[j]] > 0 || last_rank[input[i].choice[j]] == input[i].rank) {
				quota[input[i].choice[j]]--;
				admission[input[i].choice[j]].insert(input[i].id);
				last_rank[input[i].choice[j]] = input[i].rank;
				break;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		if (admission[i].size() == 0) {
			printf("\n");
			continue;
		}
		set<int>::iterator it = admission[i].begin();
		for (printf("%d", *it), it++; it != admission[i].end(); it++) {
			printf(" %d", *it);
		}
		printf("\n");
	}
	return 0;
}