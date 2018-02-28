#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;
int main() {
	int N, M, sum_tmp = 0;
	scanf("%d%d", &N, &M);
	vector<int> D(N + 1), sum(N + 1);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &D[i]);
		sum_tmp += D[i];
		sum[i] = sum_tmp;
	}

	bool flag = false;
	for (int i = 1; i <= N; i++) {
		vector<int>::iterator it = lower_bound(sum.begin() + i, sum.end(), M + sum[i - 1]);
		int posi = it - sum.begin();
		if (posi <= N && *it == M + sum[i - 1]) {
			flag = true;
			printf("%d-%d\n", i, posi);
		}
	}
	if (!flag) {
		int opt = INF;
		vector<int> ans;
		for (int i = 1; i <= N; i++) {
			vector<int>::iterator it = upper_bound(sum.begin() + i, sum.end(), M + sum[i - 1]);
			int posi = it - sum.begin();
			if (posi <= N && *it > M + sum[i - 1]) {
				if (*it - (M + sum[i - 1]) < opt) {
					opt = *it - (M + sum[i - 1]);
					ans.clear();
					ans.push_back(i);
					ans.push_back(posi);
				}
				else if (*it - (M + sum[i - 1]) == opt) {
					ans.push_back(i);
					ans.push_back(posi);
				}
			}
		}
		for (int i = 0; i < ans.size(); i += 2) {
			printf("%d-%d\n", ans[i], ans[i + 1]);
		}
	}
	return 0;
}