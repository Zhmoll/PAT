#include <cstdio>
#include <algorithm>
int dis[100005];
int main() {
	int N, tmp, sum = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &tmp);
		sum += tmp;
		dis[i] = sum;
	}
	int c1, c2, M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &c1, &c2);
		if (c1 > c2) {
			int tmp = c1;
			c1 = c2;
			c2 = tmp;
		}
		int len = dis[c2 - 1] - dis[c1 - 1];
		printf("%d\n", len < sum - len ? len : sum - len);
	}
	return 0;
}