#include <cstdio>
#include <vector>
#include <set>
using namespace std;
vector<vector<int>> Adj;
int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	Adj.resize(N);
	int c1, c2;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &c1, &c2);
		Adj[c1].push_back(c2);
		Adj[c2].push_back(c1);
	}
	int K, S, tmp;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &S);
		set<int> si;
		for (int j = 0; j < S; j++) {
			scanf("%d", &tmp);
			si.insert(tmp);
		}

		bool flag = true;
		for (int j = 0; j < N; j++) {
			if (si.count(j) == 0)
				for (int k = 0; k < Adj[j].size(); k++) {
					if (si.count(Adj[j][k]) == 0) {
						flag = false;
						goto out;
					}
				}

		}
	out:
		if (flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}