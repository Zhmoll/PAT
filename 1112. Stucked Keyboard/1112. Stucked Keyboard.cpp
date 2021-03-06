#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
	string sentence;
	map<char, bool> key_guyi; // false 没故意, true 故意
	map<char, bool> key_fail; // false 没坏, true 坏了
	vector<char> order;
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
				if (!key_fail[check])
					order.push_back(check);
				key_fail[check] = true;
			}
			else {
				key_guyi[check] = true;
			}
			check = sentence[i];
			check_times = 1;
		}
	}

	if (check_times%times == 0) {
		if (!key_fail[check])
			order.push_back(check);
		key_fail[check] = true;
	}

	set<char> real_fail;
	for (int i = 0; i < order.size(); i++) {
		if (key_fail[order[i]] && !key_guyi[order[i]]) {
			printf("%c", order[i]);
			real_fail.insert(order[i]);
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