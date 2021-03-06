#include <iostream>
#include <string>
using namespace std;

long long getDigit(char c) {
	if (c >= '0'&&c <= '9') return c - '0';
	else return c - 'a' + 10;
}

long long getnum(string number, long long radix) {
	long long result = 0;
	long long digit;
	for (int i = 0; i < number.length(); i++) {
		digit = getDigit(number[i]);
		result = result * radix + digit;
		if (result < 0) return -1;
	}
	return result;
}

int main() {
	string N1, N2;
	int tag, radix;
	cin >> N1 >> N2 >> tag >> radix;
	if (tag == 2) swap(N1, N2);

	long long number1 = getnum(N1, radix);
	long long minradix = 1;
	for (int i = 0; i < N2.length(); i++) {
		if (getDigit(N2[i]) > minradix) minradix = getDigit(N2[i]);
	}
	minradix++;

	long long left = minradix;
	long long right = number1 + 1;

	while (left <= right) {
		long long mid = (left + right) / 2;
		long long number2 = getnum(N2, mid);
		if (number2 == -1) {
			right = mid - 1;
			continue;
		}
		long long diff = number1 - number2;
		if (diff == 0) {
			printf("%ld", mid);
			return 0;
		}
		else if (diff < 0) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	printf("Impossible");
	return 0;
}