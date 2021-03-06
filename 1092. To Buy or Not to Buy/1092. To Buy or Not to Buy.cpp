#include <cstdio>
#include <cstring>
char str1[1005], str2[1005];
int char_count[10 + 26 + 26 + 5] = { 0 };
inline int hash_char(char a) {
	if (a >= '0' && a <= '9') return a - '0';
	if (a >= 'a'&& a <= 'z') return a - 'a' + 10;
	if (a >= 'A'&& a <= 'Z') return a - 'A' + 36;
}
int main() {
	scanf("%s", str1);
	scanf("%s", str2);
	int count = 0;
	for (int i = 0; i < strlen(str2); i++) {
		char_count[hash_char(str2[i])]++;
	}
	for (int i = 0; i < strlen(str1); i++) {
		if (char_count[hash_char(str1[i])] != 0) {
			char_count[hash_char(str1[i])]--;
			count++;
		}
	}
	if (count == strlen(str2)) {
		printf("Yes %d", strlen(str1) - strlen(str2));
	}
	else {
		printf("No %d", strlen(str2) - count);
	}
	return 0;
}