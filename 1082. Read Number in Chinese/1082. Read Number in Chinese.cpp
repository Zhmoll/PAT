#include <cstdio>
#include <cstring>

int main() {
	char str[15] = { 0 };
	scanf("%s", str);

	bool negative = false;
	if (str[0] == '-') {
		negative = true;
	}
	else {
		negative = false;
	}

	int len, i;
	if (negative) {
		len = strlen(str) - 1;
		printf("Fu ");
		i = 1;
	}
	else {
		len = strlen(str);
		i = 0;
	}

	char wei[10][10] = { "", "","Shi","Bai","Qian","","Shi","Bai","Qian","Yi" };
	char digi[10][10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };

	bool zeroFlag = false;
	bool firstSpaceControl = true;
	for (; i < strlen(str); i++, len--) {
		if ((str[i] - '0') == 0 && 1 == strlen(str)) printf("ling");
		if ((str[i] - '0') == 0) {
			zeroFlag = true;
		}
		else {
			if (zeroFlag) {
				printf(" ");
				printf("ling");
				zeroFlag = false;
			}
			if (firstSpaceControl) {
				firstSpaceControl = false;
			}
			else {
				printf(" ");
			}
			printf("%s", digi[str[i] - '0']);
			if (len != 5 && len!=1) {
				printf(" ");
				printf("%s", wei[len]);
			}
		}

		if (len == 5) {
			printf(" ");
			printf("Wan");
			zeroFlag = false;
		}
	}
	return 0;
}