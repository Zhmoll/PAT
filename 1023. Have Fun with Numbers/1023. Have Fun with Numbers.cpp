#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	int digi[10] = { 0 };
	int len1 = str.length();
	for (int i = 0; i < len1; i++) {
		digi[str[i] - '0']++;
	}

	bool jinwei = false;
	for (int i = len1 - 1; i >= 0; i--) {
		int cur = (str[i] - '0') * 2 + jinwei;
		if (cur > 9) {
			str[i] = cur + '0' - 10;
			jinwei = true;
		}
		else {
			str[i] = cur + '0';
			jinwei = false;
		}
		digi[str[i] - '0']--;
	}


	if (jinwei)
		cout << "No" << endl << "1" << str;
	else {
		bool flag = true;
		for (int i = 0; i < 10; i++) {
			if (digi[i] != 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "Yes" << endl << str;
		}
		else
			cout << "No" << endl << str;
	}
	return 0;
}