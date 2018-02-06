#include <cstdio>
#include <cstdlib>

int main() {

	int K1, K2, tmp1;
	double tmp2;
	double a1[1005] = { 0 }, a2[1005] = { 0 };
	double a3[1005] = { 0 };
	scanf("%d", &K1);
	for (int i = 0; i < K1; i++) {
		scanf("%d%lf", &tmp1, &tmp2);
		a1[tmp1] += tmp2;
	}

	scanf("%d", &K2);
	for (int i = 0; i < K2; i++) {
		scanf("%d%lf", &tmp1, &tmp2);
		a2[tmp1] += tmp2;
	}

	int count = 0;
	int minIndex = 1004;
	for (int i = 1004; i >=0; i--) {
		a3[i] = a1[i] + a2[i];
		if (a3[i] != 0) {
			count++;
			minIndex = i;
		}
	}

	printf("%d", count);
	if (count > 0)printf(" ");

	for (int i = 1004; i >= minIndex; i--) {
		if (a3[i] == 0) continue;
		printf("%d %.1f", i, a3[i]);
		if (i != minIndex)printf(" ");
	}

	system("pause");
	return 0;
}