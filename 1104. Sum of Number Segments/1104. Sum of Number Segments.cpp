#include <cstdio>
int main() {
	int N;
	double sum = 0, tmp;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lf", &tmp);
		sum += tmp * (i + 1)*(N - i);
	}
	printf("%.2f", sum);
	return 0;
}