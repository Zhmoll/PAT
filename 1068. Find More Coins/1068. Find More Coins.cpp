#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	vector<int> coin(N + 1);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &coin[i]);
	}
	sort(coin.begin() + 1, coin.end(), greater<int>());

	vector<int> dp(M + 1);
	vector<vector<bool>> choice(N + 1);
	for (int i = 0; i <= N; i++) {
		choice[i].resize(M + 1);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = M; j >= coin[i]; j--) {
			if (dp[j] <= dp[j - coin[i]] + coin[i]) {
				dp[j] = dp[j - coin[i]] + coin[i];
				choice[i][j] = true;
			}
		}
	}

	if (dp[M] != M) printf("No Solution");
	else {
		int i = N, j = M;
		vector<int> path;
		for (; i >= 0; i--) {
			if (choice[i][j]) {
				path.push_back(coin[i]);
				j -= coin[i];
			}
		}
		for (int i = 0; i < path.size(); i++) {
			printf("%d", path[i]);
			if (i != path.size() - 1) printf(" ");
		}
	}

	return 0;
}