#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
char digi_low[13][10] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
char digi_high[13][10] = { "","tam", "hel","maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

int main() {
	int N;
	cin >> N;
	getchar();
	string line;
	for (int i = 0; i < N; i++) {
		getline(cin, line);
		if (line[0] >= '0'&&line[0] <= '9') {
			// 十进制
			int number = stoi(line);

			if (number % 13 == 0 && number!=0) {
				number /= 13;
				cout << digi_high[number] << endl;
			}
			else {
				int digi = number % 13;
				number /= 13;
				string result = digi_low[digi];
				if (number != 0) {
					result.insert(0, " ");
					result.insert(0, digi_high[number]);
				}
				cout << result << endl;
			}
		}
		else {
			int posi = line.find(" ");
			if (posi != string::npos) {
				// 两位
				string s1 = line.substr(0, posi);
				string s2 = line.substr(posi+1);
				int i, j;
				for (i = 0; i < 13; i++) {
					if (s1 == digi_high[i]) {
						break;
					}
				}
				for (j = 0; j < 13; j++) {
					if (s2 == digi_low[j]) {
						break;
					}
				}
				cout << i * 13 + j << endl;
			}
			else {
				// 一位
				int i;
				bool flag = false;
				for (i = 0; i < 13; i++) {
					if (line == digi_low[i]) {
						break;
					}
					if (line == digi_high[i]) {
						flag = true;
						break;
					}
				}
				if(flag)
					cout << i*13 << endl;
				else
					cout << i << endl;
			}
		}
	}
	return 0;
}