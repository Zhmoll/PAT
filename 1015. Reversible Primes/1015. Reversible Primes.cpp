#include <cstdio>
#include <cmath>
bool isPrime(int a) {
	if (a == 0 || a == 1) return false;
	bool flag = true;
	for (int i = 2; i <= sqrt(a); i++) {
		if (a%i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
}

int main() {
	int a, b;
	while (true) {
		scanf("%d", &a);
		if (a < 0) break;
		scanf("%d", &b);

		int source = a;
		int re = 0;
		while (a != 0) {
			re = re * b + a % b;
			a /= b;
		}

		if (isPrime(source) && isPrime(re)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}