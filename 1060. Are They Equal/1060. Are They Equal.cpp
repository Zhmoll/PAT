#include <iostream>
#include <string>

using namespace std;

int main() {

	int digit = 0;
	string flt1, flt2;
	string weishu1, weishu2;
	int zhishu1 = 0, zhishu2 = 0;

	cin >> digit >> flt1 >> flt2;

	// 去除前导0
	while (flt1[0] == '0') { 
		flt1.erase(0, 1);
	}

	int pointPos1 = flt1.find('.');
	if (pointPos1 != -1) {
		zhishu1 = pointPos1;
		flt1.erase(pointPos1,1);
		while (flt1[0] == '0') {
			flt1.erase(0, 1);
			zhishu1--;
		}
	}
	else {
		zhishu1 = flt1.length();
	}
	weishu1 = flt1.substr(0, digit);
	int tmp = digit - weishu1.length();
	if (tmp == digit) {
		zhishu1 = 0;
	}
	while (tmp--) {
		weishu1.append("0");
	}

	while (flt2[0] == '0') {
		flt2.erase(0, 1);
	}

	int pointPos2 = flt2.find('.');
	if (pointPos2 != -1) {
		zhishu2 = pointPos2;
		flt2.erase(pointPos2, 1);
		while (flt2[0] == '0') {
			flt2.erase(0, 1);
			zhishu2--;
		}
	}
	else {
		zhishu2 = flt2.length();
	}
	weishu2 = flt2.substr(0, digit);
	tmp = digit - weishu2.length();
	if (tmp == digit) {
		zhishu2 = 0;
	}
	while (tmp--) {
		weishu2.append("0");
	}

	if (zhishu1 == zhishu2 && weishu1 == weishu2) {
		cout << "YES 0." << weishu1 << "*10^" << zhishu1;
	}
	else {
		cout << "NO 0." << weishu1 << "*10^" << zhishu1 << " 0." << weishu2 << "*10^" << zhishu2;
	}

	return 0;
}