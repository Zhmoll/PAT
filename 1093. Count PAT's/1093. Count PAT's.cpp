#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string str;
	cin >> str;

	int p_count = 0;
	vector<int> p_left(str.length());
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'P') {
			p_count++;
		}
			p_left[i] = p_count;
	}

	int t_count = 0;
	vector<int> t_right(str.length());
	for (int i = str.length() - 1; i >= 0; i--) {
		if (str[i] == 'T') {
			t_count++;
		}
			t_right[i] = t_count;
	}

	long long count = 0;
	for (string::iterator it = str.begin(); it != str.end(); it++) {
		if (*it == 'A') {
			count += p_left[it - str.begin()] * t_right[it - str.begin()];
		}
	}

	cout << count % 1000000007;

	return 0;
}