#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int a = 0, b = 0;
	int sum = 0;
	scanf("%d%d", &a, &b);

	sum = a + b;

	char str[15] = { 0 };
	char str_result[15] = { 0 };
	if (sum < 0) {
		sum = -sum;
		printf("-");
	}

	sprintf(str, "%d", sum);
	int len = strlen(str);
	int count = 0;
	int j = 0;
	for (int i = len - 1; i >= 0; i--) {
		str_result[j++] = str[i];
		count++;
		if (count > 2) {
			count = 0;
			str_result[j++] = ',';
		}
	}
	str_result[j] = 0;

	for (int i = strlen(str_result) - 1; i >= 0; i--) {
		if (i == strlen(str_result) - 1 && str_result[i] == ',') continue;
		printf("%c", str_result[i]);
	}

	system("pause");
	return 0;
}