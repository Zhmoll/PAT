#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	double tmp;
	double sum = 0;

	for (int i = 0; i < N; i++) {
		scanf("%lf", &tmp);
		sum += tmp * (i + 1)*(N - i);
	}
	printf("%.2f", sum);
	return 0;
}