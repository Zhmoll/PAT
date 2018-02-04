#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int a = 0, b = 0;
	int sum = 0;
	char str[20] = {};
	scanf("%d%d", &a, &b);
	sum = a + b;
	if (sum < 0) {
		sum = -sum;
		printf("-");
	}

	int temp1 = sum / 1000000;
	bool hasTemp1 = false;
	if (temp1 != 0) {
		printf("%d,", temp1);
		hasTemp1 = true;
	}

	int temp2 = sum / 1000 - temp1 * 1000;
	bool hasTemp2 = false;
	if (hasTemp1) {
		printf("%03d,", temp2);
	}
	else if (temp2 != 0) {
		printf("%d,", temp2);
		hasTemp2 = true;
	}

	int temp3 = sum % 1000;
	if (hasTemp1 || hasTemp2) {
		printf("%03d", temp3);
	}
	else {
		printf("%d", temp3);
	}

	system("pause");
	return 0;
}