#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	getchar();
	string tmp, last;
	for (int i = 0; i < N; i++) {
		getline(cin, tmp);
		if (i == 0) {
			last = tmp;
			continue;
		}
		else {
			int len = tmp.length() < last.length() ? tmp.length() : last.length();
			int j;
			for (j = 0; j < len; j++) {
				if (last[last.length() - 1 - j] != tmp[tmp.length() - 1 - j]) {
					break;
				}
			}
			last = tmp.substr(tmp.length() - j);
		}
	}
	if (last == "") cout << "nai";
	else cout << last;
	return 0;
}