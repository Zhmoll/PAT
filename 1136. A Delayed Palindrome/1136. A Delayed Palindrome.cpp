#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string Lplus(string a, string b) {
	string result;
	int digi_sum;
	bool jinwei = false;
	for (int i = a.size() - 1; i >= 0; i--) {
		digi_sum = ((a[i] - '0') + (b[i] - '0') + jinwei) % 10;
		jinwei = ((a[i] - '0') + (b[i] - '0') + jinwei) / 10;
		result.insert(0, to_string(digi_sum));
	}
	if (jinwei) {
		result.insert(0, "1");
	}
	return result;
}

bool isPali(string a) {
	bool flag = true;
	for (int i = 0; i < a.size() / 2; i++) {
		if (a[i] != a[a.size() - 1 - i]) {
			flag = false;
			break;
		}
	}
	return flag;
}

int main() {
	string number, reverse_number;
	cin >> number;
	int i = 0;
	while (!isPali(number) && i < 10) {
		reverse_number = number;
		reverse(reverse_number.begin(), reverse_number.end());
		printf("%s + %s = ", number.c_str(), reverse_number.c_str());
		number = Lplus(number, reverse_number);
		printf("%s\n", number.c_str());
		i++;
	}

	if (isPali(number)) {
		printf("%s is a palindromic number.", number.c_str());
	}
	else {
		printf("Not found in 10 iterations.");
	}

	return 0;
}