#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	string str;
	cin >> str;
	int n1 = 1, n2 = str.length() + 2 - n1 * 2;
	while (n1 <= str.length() + 2 - n1 * 2) {
		n2 = str.length() + 2 - n1 * 2;
		n1++;
	}
	n1--;
	vector<vector<char>> output(n1);
	for (int i = 0; i < output.size(); i++) {
		output[i].resize(n2, ' ');
	}

	int a = 0, b = 0;
	bool down = true;
	bool right = false;
	bool up = false;
	for (int i = 0; i < str.length(); i++) {
		output[a][b] = str[i];
		if (down) {
			a++;
			if (a == n1) {
				a--;
				right = true;
				down = false;
				b++;
			}
			continue;
		}
		if (right) {
			b++;
			if (b == n2) {
				b--;
				a--;
				right = false;
				up = true;
			}
			continue;
		}
		if (up) {
			a--;
		}
	}
	for (int i = 0; i < output.size(); i++) {
		for (int j = 0; j < output[i].size(); j++) {
			printf("%c", output[i][j]);
		}
		printf("\n");
	}
	return 0;
}