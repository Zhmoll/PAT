#include <cstdio>
#include <string>
#include <map>
using namespace std;
bool isChar(char a) {
	if ((a >= '0' && a <= '9')
		|| (a >= 'a'&&a <= 'z')
		|| (a >= 'A'&&a <= 'Z'))
		return true;
	else return false;
}

int main() {
	string str;
	char tmp;
	map<string, int> book;
	while ((tmp = getchar()) != '\n') {
		if (isChar(tmp)) {
			if (tmp >= 'A' && tmp <= 'Z')
				tmp = tmp - 'A' + 'a';
			char tmp_str[2] = { '\0' };
			tmp_str[0] = tmp;
			str.append(tmp_str);
		}
		else if (str != "") {
			book[str]++;
			str = "";
		}
	}
	if (str != "") {
		book[str]++;
		str = "";
	}

	int max_count = 0;
	string max_str;
	map<string, int>::iterator it = book.begin();
	for (; it != book.end(); it++) {
		if (it->second > max_count) {
			max_str = it->first;
			max_count = it->second;
		}
	}
	printf("%s %d", max_str.c_str(), max_count);
	return 0;
}