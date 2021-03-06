#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {
	string source, exact;
	cin >> source >> exact;
	int point = 0;
	vector<char> broken;
	set<char> broken_set;

	int i = 0;
	while (i < source.length()) {
		if (source[i] != exact[point]) {
			char character = source[i];
			if (character >= 'a' && character <= 'z') {
				character += 'A' - 'a';
			}
			if (broken_set.find(character) == broken_set.end()) {
				broken.push_back(character);
				broken_set.insert(character);
			}
			i++;
		}
		else {
			i++;
			point++;
		}
	}

	for (int i = 0; i < broken.size(); i++) {
		cout << broken[i];
	}

	return 0;
}