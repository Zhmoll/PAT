#include <iostream>
#include <string>

using namespace std;

void process(string &flt, int digit, string &weishu, int &zhishu) {
	// 去除前导 0 
	while (flt[0] == '0' && flt.length() > 0)
		flt.erase(0, 1);

	int pointPos = flt.find('.');
	if (pointPos != -1) {
		zhishu = pointPos;
		flt.erase(pointPos, 1);

		if (pointPos == 0) {
			while (flt[0] == '0'&& flt.length() > 0) {
				flt.erase(0, 1);
				zhishu--;
			}
			if (flt == "") zhishu = 0;
		}
	}
	else {
		zhishu = flt.length();
	}

	weishu = flt.substr(0, digit);
	int tmp = digit - weishu.length();
	while (tmp--) {
		weishu.append("0");
	}
}

int main() {
	int digit = 0;
	string flt1, flt2;
	string weishu1, weishu2;
	int zhishu1 = 0, zhishu2 = 0;

	cin >> digit >> flt1 >> flt2;

	process(flt1, digit, weishu1, zhishu1);
	process(flt2, digit, weishu2, zhishu2);

	if (zhishu1 == zhishu2 && weishu1 == weishu2)
		cout << "YES 0." << weishu1 << "*10^" << zhishu1;
	else
		cout << "NO 0." << weishu1 << "*10^" << zhishu1 << " 0." << weishu2 << "*10^" << zhishu2;
	
	return 0;
}