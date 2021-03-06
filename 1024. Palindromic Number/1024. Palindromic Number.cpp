#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isPali(string number) {
	bool flag = true;
	for (int i = 0; i < number.length() / 2; i++) {
		if (number[i] != number[number.length() - 1 - i]) {
			flag = false;
			break;
		}
	}
	return flag;
}

string plus_re(string a) {
	bool jinwei = false;
	string result;
	int digi = 0;
	char digi_str[2] = { 0 };
	for (int i = a.length() - 1; i >= 0; i--) {
		digi = a[i] - '0' + a[a.length() - 1 - i] - '0' + jinwei;
		jinwei = false;
		if (digi > 9) {
			digi = digi - 10;
			jinwei = true;
		}
		digi_str[0] = digi + '0';
		result.insert(0, digi_str);
	}
	if (jinwei) {
		digi_str[0] = '1';
		result.insert(0, digi_str);
	}
	return result;
}

int main() {
	string N;
	int K, count = 0;
	cin >> N >> K;
	string current, result;
	result = N;
	for (int i = 0; i < K; i++) {
		if (isPali(result)) break;
		current = result;
		result = plus_re(current);
		count++;
	}
	cout << result << endl << count;
	return 0;
}