#include <cstdio>
#include <cmath>

bool isPrime(int x) {
	bool flag = true;
	if (x < 2) return false;
	for (int i = 2; i <= sqrt((double)x); i++) {
		if (x % i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
}

int main() {
	while (1) {
		int N, D;
		scanf("%d", &N);
		if (N < 0) break;
		scanf("%d", &D);
		if (!isPrime(N)) {
			printf("No\n");
			continue;
		}

		int reverse = 0;
		while (N != 0) {
			reverse = reverse * D + N % D;
			N /= D;
		}
		if (isPrime(reverse)) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}

	return 0;
}