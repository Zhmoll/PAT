#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main() {
	int a, b, sum;
	scanf("%d%d", &a, &b);
	sum = a + b;

	char str[10] = { 0 };
	sprintf(str, "%d", sum);

	string result;

	int count = 0;
	for (int i = strlen(str) - 1; i >= 0; i--) {
		count++;
		char tmp[2] = { 0 };
		tmp[0] = str[i];
		result.insert(0, tmp);
		if (count == 3) {
			count = 0;
			if (i == 0) continue;
			if (i == 1 && str[0] == '-') continue;
			tmp[0] = ',';
			result.insert(0, tmp);
		}
	}
	printf("%s", result.c_str());
	return 0;
}