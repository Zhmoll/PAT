// 20点54分
#include <iostream>
#include <string>
using namespace std;

string Standard(string num, int N) {
	int dot_posi = num.find(".");
	int zhishu = dot_posi == -1 ? 0 : -(num.length() - dot_posi - 1);
	if (dot_posi != -1) num.erase(dot_posi, 1);
	while (num.length() > 1 && num[0] == '0')
		num.erase(0, 1);
	if (num == "0") {
		zhishu = -1;
	}
	zhishu += num.length();
	char zhishu_str[101];
	sprintf(zhishu_str, "%d", zhishu);
	if (N < num.length()) {
		num.erase(N);
	}
	else {
		while (num.length() < N) {
			num.append("0");
		}
	}
	num.insert(0, "0.");
	num.append("*10^");
	num.append(zhishu_str);
	return num;
}

int main() {
	int N;
	string num1, num2;
	cin >> N >> num1 >> num2;
	string snum1 = Standard(num1, N);
	string snum2 = Standard(num2, N);
	if (snum1 == snum2) {
		cout << "YES " << snum1;
	}
	else {
		cout << "NO " << snum1 << " " << snum2;
	}
	return 0;
}