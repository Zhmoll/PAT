#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct mouse {
	int weight;
	int order;
	int rank;
};

bool cmp(mouse &a, mouse &b) {
	return a.order < b.order;
}

int main() {
	int P, G, tmp;
	scanf("%d %d", &P, &G);
	vector<int> W;
	for (int i = 0; i < P; i++) {
		scanf("%d", &tmp);
		W.push_back(tmp);
	}
	vector<mouse> player(P);
	for (int i = 0; i < P; i++) {
		scanf("%d", &tmp);
		player[i].weight = W[tmp];
		player[i].order = tmp;
	}

	queue<mouse*> q;
	for (int i = 0; i < P; i++) {
		q.push(&player[i]);
	}

	while (q.size() != 1) {
		int total_group = q.size() / G;
		if (q.size() % G != 0) total_group++;
		queue<mouse*> tmp_q;
		while (q.size() > 0) {
			int max = -1;
			mouse *max_point = NULL;
			for (int i = 0; i < G && q.size()>0; i++) {
				q.front()->rank = total_group + 1;
				if (max == -1) {
					max = q.front()->weight;
					max_point = q.front();
				}
				else if (q.front()->weight > max) {
					max = q.front()->weight;
					max_point = q.front();
				}
				q.pop();
			}
			tmp_q.push(max_point);
		}
		q = tmp_q;
	}
	q.front()->rank = 1;
	sort(player.begin(), player.end(), cmp);
	for (int i = 0; i < P; i++) {
		printf("%d", player[i].rank);
		if (i != P - 1) printf(" ");
	}
	return 0;
}