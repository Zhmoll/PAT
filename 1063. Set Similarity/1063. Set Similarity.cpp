#include <set>
#include <vector>
#include <cstdio>

using namespace std;

double calDiff(set<int> &a, set<int> &b) {
	set<int> all = a;
	for (set<int>::iterator it = b.begin(); it!=b.end(); it++) {
		all.insert(*it);
	}
	int Nt = all.size();
	int Nc = (b.size() + a.size()) - Nt;
	return (double)Nc / (double)Nt;
}

int main() {
	int N;
	scanf("%d", &N);
	vector<set<int>> num_set(N);
	for (int i = 0; i < N; i++) {
		int M, tmp;
		scanf("%d", &M);
		for (int j = 0; j < M; j++) {
			scanf("%d", &tmp);
			num_set[i].insert(tmp);
		}
	}
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		double result = calDiff(num_set[tmp1 - 1], num_set[tmp2 - 1]) * 100;
		printf("%.01f%%\n", result);
	}
	return 0;
}