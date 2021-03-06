#include <cstdio>
#include <vector>
using namespace std;
int main() {
	int K1, K2;
	vector<double> a1(1001), a2(1001), fin(2001);
	int ci;
	double xi;
	scanf("%d", &K1);
	for (int i = 0; i < K1; i++) {
		scanf("%d %lf", &ci, &xi);
		a1[ci] = xi;
	}
	scanf("%d", &K2);
	for (int i = 0; i < K2; i++) {
		scanf("%d %lf", &ci, &xi);
		a2[ci] = xi;
	}

	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			fin[i + j] += a1[i] * a2[j];
		}
	}

	int count = 0;
	for (int i = 0; i < 2001; i++) {
		if (fin[i] != 0) count++;
	}
	printf("%d", count);

	for (int i = 2000; i >= 0; i--) {
		if (fin[i] != 0)
			printf(" %d %.1f", i, fin[i]);
	}

	return 0;
}