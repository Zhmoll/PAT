#include <cstdio>

int main() {

	int T = 0;
	scanf("%d", &T);

	long long num1, num2, compare;
	long long sum;

	for (int i = 0; i < T; i++) {
		scanf("%lld %lld %lld", &num1, &num2, &compare);
		sum = num1 + num2;
		if (num1 > 0 && num2 > 0 && sum < 0)
			printf("Case #%d: true\n", i + 1);
		else if (num1 < 0 && num2 < 0 && sum >= 0)
			printf("Case #%d: false\n", i + 1);
		else {
			if (sum > compare)
				printf("Case #%d: true\n", i + 1);
			else
				printf("Case #%d: false\n", i + 1);
		}
	}
	return 0;
}