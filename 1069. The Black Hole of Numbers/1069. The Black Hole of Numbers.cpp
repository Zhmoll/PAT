#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int cmp(char a, char b) {
	return a > b;
}

int main() {

	int start = 0;
	scanf("%d", &start);

	int result = start;
	string str;
	char tmp[5];
	int first, second;
	do {
		sprintf(tmp, "%04d", result);
		if (tmp[0] == tmp[1] && tmp[1] == tmp[2] && tmp[2] == tmp[3]) {
			printf("%04d - %04d = 0000\n", result, result);
			break;
		}
		str = tmp;
		sort(str.begin(), str.end(), cmp);
		first = stoi(str);
		reverse(str.begin(), str.end());
		second = stoi(str);
		result = first - second;
		printf("%04d - %04d = %04d\n", first, second, result);
	} while (result != 6174);

	return 0;
}