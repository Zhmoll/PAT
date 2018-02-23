#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	set<char> filter;
	for (int i = 0; i < str2.length(); i++) {
		filter.insert(str2[i]);
	}
	for (int i = 0; i < str1.length(); i++) {
		if (filter.count(str1[i]) == 0)
			printf("%c", str1[i]);
	}
	return 0;
}