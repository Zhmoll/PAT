#include <cstdio>

int main() {
	int N;
	long long a, b, sum, cmp;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld%lld%lld", &a, &b, &cmp);
		sum = a + b;
		if (a < 0 && b < 0 && sum >= 0) {
			printf("Case #%d: false\n", i + 1);
		}
		else if (a > 0 && b > 0 && sum <= 0) {
			printf("Case #%d: true\n", i + 1);
		}
		else if (sum > cmp) {
			printf("Case #%d: true\n", i + 1);
		}
		else {
			printf("Case #%d: false\n", i + 1);
		}
	}
	return 0;
}