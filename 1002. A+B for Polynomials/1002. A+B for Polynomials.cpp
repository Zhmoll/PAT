#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int K1;
	scanf("%d", &K1);
	vector<double> poly(1001);
	int ci;
	double xi;
	for (int i = 0; i < K1; i++) {
		scanf("%d %lf", &ci, &xi);
		poly[ci] = xi;
	}
	int K2;
	scanf("%d", &K2);
	for (int i = 0; i < K2; i++) {
		scanf("%d %lf", &ci, &xi);
		poly[ci] += xi;
	}
	int count = 0;
	for (int i = 1000; i >= 0; i--) {
		if (poly[i] != 0) count++;
	}
	printf("%d", count);
	for (int i = 1000; i >= 0; i--) {
		if (poly[i] != 0) {
			printf(" %d %.1f", i, poly[i]);
		}
	}
	return 0;
}