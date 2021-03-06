#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, M, L, tmp;
	scanf("%d", &N);
	scanf("%d", &M);
	vector<int> rank(N + 1), order(M + 1);
	fill(rank.begin(), rank.end(), -1);
	for (int i = 1; i <= M; i++) {
		scanf("%d", &tmp);
		order[i] = tmp;
		rank[tmp] = i;
	}
	scanf("%d", &L);
	vector<int> input(1);
	for (int i = 0; i < L; i++) {
		scanf("%d", &tmp);
		if (rank[tmp] != -1)
			input.push_back(tmp);
	}

	vector<int> dp(input.size() + 1);
	int len = -1;
	for (int i = 1; i < input.size(); i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (rank[input[i]] >= rank[input[j]] && (dp[j] + 1 > dp[j])) {
				dp[i] = dp[j] + 1;
			}
		}
		len = max(len, dp[i]);
	}
	printf("%d", len);
	return 0;
}