#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
	string sentence;
	map<char, bool> key_guyi; // false 没故意, true 故意
	map<char, bool> key_fail; // false 没坏, true 坏了
	map<char, bool> key_present; // false 没出现, true 出现过了
	int times = 0;
	cin >> times >> sentence;

	char check = sentence[0];
	int check_times = 1;
	key_present[sentence[0]] = true;
	for (int i = 1; i < sentence.length(); i++) {
		key_present[sentence[i]] = true;
		if (sentence[i] == check) {
			check_times++;
		}
		else {
			if (check_times%times == 0) {
				key_fail[check] = true;
			}
			else {
				key_guyi[check] = true;
			}
			check = sentence[i];
			check_times = 1;
		}
	}

	set<char> real_fail;
	map<char, bool>::iterator it = key_present.begin();
	for (; it != key_present.end(); it++) {
		char key = it->first;
		bool present = it->second;
		if (present) {
			if (key_fail[key] && !key_guyi[key]) {
				printf("%c", key);
				real_fail.insert(key);
			}
		}
	}

	printf("\n");
	set<char>::iterator setit = real_fail.begin();
	for (int i = 0; i < real_fail.size(); i++, setit++) {
		for (int j = 0; j < sentence.length(); j++) {
			if (sentence[j] == *setit) {
				sentence.erase(j, times-1);
			}
		}
	}
	printf("%s", sentence.c_str());

	return 0;
}