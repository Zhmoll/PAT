#include <cstdio>

int main() {
	int a1, a2, a3, b1, b2, b3, c1, c2, c3;
	scanf("%d.%d.%d", &a1, &a2, &a3);
	scanf("%d.%d.%d", &b1, &b2, &b3);

	int jinwei1 = (a3 + b3) / 29;
	c3 = (a3 + b3) % 29;

	int jinwei2 = (a2 + b2 + jinwei1) / 17;
	c2 = (a2 + b2 + jinwei1) % 17;

	c1 = a1 + b1 + jinwei2;

	printf("%d.%d.%d", c1, c2, c3);
	return 0;
}