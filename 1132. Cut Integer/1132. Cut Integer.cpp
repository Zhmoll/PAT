#include <cstdio>
#include <cstring>

int main() {
	int N;
	scanf("%d", &N);
	char str[35] = { 0 }, str1[35] = { 0 }, str2[35] = { 0 };
	for (int i = 0; i < N; i++) {
		int Z;
		scanf("%d", &Z);
		sprintf(str, "%d", Z);
		int half = strlen(str) / 2;

		int j = 0;
		for (; j < half; j++) {
			str1[j] = str[j];
		}
		str1[j] = 0;

		j = 0;
		for (; j < half; j++) {
			str2[j] = str[j + half];
		}
		str2[j] = 0;

		int num1, num2;
		sscanf(str1, "%d", &num1);
		sscanf(str2, "%d", &num2);

		long long a = num1 * num2;
		if (a == 0) {
			printf("No\n");
			continue;
		}
		long long b = (long long)Z % a;

		if (b == 0) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}

	return 0;
}