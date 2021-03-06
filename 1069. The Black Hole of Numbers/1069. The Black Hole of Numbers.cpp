#include <cstdio>
#include <algorithm>

using namespace std;

int cmp(char a, char b) {
	return a > b;
}

int main() {
	int result = 0;
	scanf("%d", &result);
	
	char tmp[5];
	int first, second;
	do {
		sprintf(tmp, "%04d", result);
		if (tmp[0] == tmp[1] && tmp[1] == tmp[2] && tmp[2] == tmp[3]) {
			printf("%04d - %04d = 0000\n", result, result);
			break;
		}
		sort(tmp, tmp + 4, cmp);
		sscanf(tmp, "%d", &first);
		reverse(tmp, tmp + 4);
		sscanf(tmp, "%d", &second);
		result = first - second;
		printf("%04d - %04d = %04d\n", first, second, result);
	} while (result != 6174);

	return 0;
}