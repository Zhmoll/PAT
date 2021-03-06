#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string num;
	cin >> num;
	int e_posi = num.find("E");
	string zhishu_str = num.substr(e_posi + 1);
	int zhishu;
	sscanf(zhishu_str.c_str(), "%d", &zhishu);

	if (num[0] == '-')printf("-");
	string xiaoshu_str = num.substr(1, e_posi - 1);
	xiaoshu_str.erase(1, 1);

	if (zhishu < 0) {
		for (int i = 0; i < abs(zhishu); i++) {
			xiaoshu_str.insert(0, "0");
		}
		xiaoshu_str.insert(1, ".");
	}
	else if (zhishu > 0) {
		if (xiaoshu_str.length() - 1 > zhishu) {
			xiaoshu_str.insert(zhishu + 1, ".");
		}
		else {
			int len = xiaoshu_str.length();
			for (int i = 0; i < zhishu - len + 1; i++) {
				xiaoshu_str.append("0");
			}
		}
	}
	else if (zhishu == 0) {
		xiaoshu_str.insert(1, ".");
	}
	cout << xiaoshu_str;
	return 0;
}