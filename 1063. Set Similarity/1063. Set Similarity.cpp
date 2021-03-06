#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main() {
	int N, M, tmp;
	scanf("%d", &N);
	vector<set<int>> vi(N + 1);
	for (int i = 0; i < N; i++) {
		scanf("%d", &M);
		for (int j = 0; j < M; j++) {
			scanf("%d", &tmp);
			vi[i + 1].insert(tmp);
		}
	}
	int K, s1, s2;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &s1, &s2);
		set<int> &ss1 = vi[s1];
		set<int> &ss2 = vi[s2];

		int count = 0;
		set<int>::iterator it = ss1.begin();
		for (int j = 0; j < ss1.size(); j++, it++) {
			if (ss2.count(*it) == 1) count++;
		}

		printf("%.1f%%\n", (double)(count) / (ss1.size() + ss2.size() - count) * 100);
	}
	return 0;
}