#include <string>
#include <iostream>
//#include <iomanip>

using namespace std;

bool isLegal(string str) {
	// 如果有除了0~9、负号、小数点的字符
	int dotCount = 0;
	bool illegal = true;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= '0'&&str[i] <= '9')
			continue;
		else if (str[i] == '-'&& i == 0)
			continue;
		else if (str[i] == '.'
			&& i != 0
			&& str[i - 1] != '-'
			&& dotCount == 0
			&& (str.length() - (i + 1)) < 3) {
			dotCount++;
			continue;
		}
		else {
			illegal = false;
			break;
		}
	}
	if (!illegal) return false;
	double tmp = stod(str);
	if (tmp < -1000 || tmp> 1000)
		return false;
	return true;
}

int main() {
	int N;
	cin >> N;
	string tmp;
	double sum = 0;
	int count = 0;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (isLegal(tmp)) {
			sum += stod(tmp);
			count++;
		}
		else {
			cout << "ERROR: " << tmp << " is not a legal number" << endl;
		}
	}

	if (count > 1)
		printf("The average of %d numbers is %.2f", count, sum / (count*1.0));
	//cout << "The average of " << count << " numbers is " << setiosflags(ios::fixed) << setprecision(2) << sum / (count*1.0);
	else if (count == 1)
		printf("The average of 1 number is %.2f", sum / (count*1.0));
	//cout << "The average of 1 number is " << setiosflags(ios::fixed) << setprecision(2) << sum / (count*1.0);
	else
		printf("The average of 0 numbers is Undefined");
	//cout << "The average of 0 numbers is Undefined";

	return 0;
}