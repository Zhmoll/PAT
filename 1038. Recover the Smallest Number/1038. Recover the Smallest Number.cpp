#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string &a, string &b) {
	return a + b < b + a;
}

int main() {
	int N;
	scanf("%d", &N);
	vector<string> input(N);
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	sort(input.begin(), input.end(), cmp);
	bool flag = false;
	for (int i = 0; i < N; i++) {
		int len = input[i].length();
		for (int j = 0; j < len; j++) {
			if (!flag &&input[i][j] == '0') continue;
			else {
				printf("%c", input[i][j]);
				flag = true;
			}
		}
	}
	if (!flag) printf("0");
	return 0;
}