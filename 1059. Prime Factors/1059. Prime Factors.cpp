#include <cstdio>

struct factor {
	int x, cnt;
	factor() :x(0), cnt(0) {}
}fac[10];

int prime[10005];
bool not_prime[10005] = { false };
int prime_cnt = 0;

void findPrime() {
	not_prime[0] = true;
	not_prime[1] = true;
	for (int i = 2; i < 10005; i++) {
		if (!not_prime[i]) {
			prime[prime_cnt++] = i;
			for (int j = i + i; j < 10005; j += i) {
				not_prime[j] = true;
			}
		}
	}
}

int main() {
	findPrime();
	int N;
	scanf("%d", &N);
	int source = N;
	int factor_cnt = 0;
	for (int i = 0; i < prime_cnt; i++) {
		while (N != 1 && N%prime[i] == 0) {
			if (fac[factor_cnt].x == prime[i]) {
				fac[factor_cnt].cnt++;
			}
			else {
				factor_cnt++;
				fac[factor_cnt].x = prime[i];
				fac[factor_cnt].cnt++;
			}
			N /= prime[i];
		}
		if (N == 1) break;
	}
	printf("%d=", source);
	if (source == 1) printf("1");
	for (int i = 1; i <= factor_cnt; i++) {
		if (fac[i].cnt == 1) {
			printf("%d", fac[i].x);
		}
		else {
			printf("%d^%d", fac[i].x, fac[i].cnt);
		}
		if (i != factor_cnt) printf("*");
	}
	return 0;
}