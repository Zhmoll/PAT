#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() {
	char str[105] = { 0 };
	char digi[10][10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	scanf("%s", str);
	int length = strlen(str);
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += str[i] - 48;
	}

	char sum_str[5] = { 0 };
	sprintf(sum_str, "%d", sum);
	int sum_str_length = strlen(sum_str);
	for (int i = 0; i < sum_str_length; i++) {
		printf("%s", digi[sum_str[i]-48]);
		if (i != sum_str_length - 1) printf(" ");
	}

	system("pause");
	return 0;
}