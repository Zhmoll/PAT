#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string &a, string &b) {
	return a + b < b + a;
}

int main() {
	int N;
	cin >> N;
	vector<string> number;
	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		number.push_back(tmp);
	}
	sort(number.begin(), number.end(), cmp);
	string result;
	for (int i = 0; i < number.size(); i++) {
		result.append(number[i]);
	}
	int i;
	for (i = 0; i < result.length(); i++) {
		if (result[i] != '0') break;
	}
	if (result.length() == 0) cout << 0;
	else cout << result.substr(i);
	return 0;
}