#include <cstdio>
#include <cstring>

int main() {
	char string[100] = { 0 };
	scanf("%s", string);
	int length = strlen(string);
	int n1 = 0, n2;
	int space = 0;
	while (1) {
		n2 = length + 2 - 2 * n1;
		if (n1 <= n2) {
			n1++;
		}
		else {
			break;
		}
	}
	n1--;
	n2 = length + 2 - 2 * n1;
	for (int i = 0; i < n1-1; i++) {
		printf("%c", string[i]);
		for (int j = 0; j < n2 - 2; j++)printf(" ");
		printf("%c\n", string[length - 1 - i]);
	}
	for (int i = n1-1; i <= n1 + n2 - 2; i++) {
		printf("%c", string[i]);
	}

	return 0;
}