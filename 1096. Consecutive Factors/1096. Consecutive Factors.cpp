#include <cstdio>
#include <cmath>

int main() {
	long long N = 0;
	scanf("%lld", &N);

	int mem_left = 2, mem_right = 1;
	long long ji = 1;
	for (int i = 2; i <= sqrt(N) + 1; i++) {
		ji = 1;
		for (int j = i; j <= sqrt(N) + 1 && ji <= N; j++) {
			ji *= j;
			if (N%ji == 0) {
				if (j - i > mem_right - mem_left) {
					mem_right = j;
					mem_left = i;
				}
			}
			else
				break;
		}
	}

	if (mem_right == 1 && mem_left == 2) {
		printf("1\n%d", N);
	}
	else {
		printf("%d\n", mem_right - mem_left + 1);
		for (int i = mem_left; i <= mem_right; i++) {
			printf("%d", i);
			if (i != mem_right) printf("*");
		}
	}

	return 0;
}