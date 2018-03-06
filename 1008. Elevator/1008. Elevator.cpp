#include <cstdio>
int main() {
	int N, tmp;
	scanf("%d", &N);
	int current = 0;
	int total = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		if (tmp > current) {
			total += (tmp - current) * 6;
			current = tmp;
		}
		else {
			total += (current - tmp) * 4;
			current = tmp;
		}
		total += 5;
	}
	printf("%d", total);
	return 0;
}