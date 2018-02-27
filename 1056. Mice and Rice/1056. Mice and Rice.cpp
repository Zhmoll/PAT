#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct mouse {
	int init;
	int weight;
	int rank;
};

bool cmp(mouse a, mouse b) {
	return a.init < b.init;
}

int main() {
	int P, G;
	scanf("%d%d", &P, &G);
	vector<mouse> a(P);
	vector<int> weight(P);
	int tmp;
	for (int i = 0; i < P; i++) {
		scanf("%d", &tmp);
		weight[i] = tmp;
	}
	for (int i = 0; i < P; i++) {
		scanf("%d", &tmp);
		a[i].weight = weight[tmp];
		a[i].init = tmp;
	}

	queue<mouse*> q, q_tmp;
	for (int i = 0; i < P; i++) {
		q.push(&a[i]);
	}

	while (q.size() != 1) {
		int group = q.size() / G;
		int rest = q.size() % G;
		if (rest != 0) group++;

		for (int i = 0; i < group; i++) {
			int count;
			if (i == group - 1 && rest != 0) count = rest;
			else count = G;

			mouse *max = q.front();
			for (int j = 0; j < count; j++) {
				mouse *current = q.front();
				current->rank = group + 1;
				if (current->weight > max->weight) {
					max = current;
				}
				q.pop();
			}
			q_tmp.push(max);
		}
		swap(q, q_tmp);
	}
	q.front()->rank = 1;
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < a.size(); i++) {
		printf("%d", a[i].rank);
		if (i != a.size() - 1) printf(" ");
	}
	return 0;
}