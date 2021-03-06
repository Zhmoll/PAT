#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct passport {
	string username;
	string password;
};

int main() {
	int N;
	cin >> N;
	vector<passport> user(N);
	vector<passport> user_modified;
	for (int i = 0; i < N; i++) {
		cin >> user[i].username >> user[i].password;
		bool modified = false;
		for (int j = 0; j < user[i].password.size(); j++) {
			if (user[i].password[j] == '1') {
				user[i].password[j] = '@';
				modified = true;
			}
			if (user[i].password[j] == '0') {
				user[i].password[j] = '%';
				modified = true;
			}
			if (user[i].password[j] == 'l') {
				user[i].password[j] = 'L';
				modified = true;
			}
			if (user[i].password[j] == 'O') {
				user[i].password[j] = 'o';
				modified = true;
			}
		}
		if (modified)
			user_modified.push_back(user[i]);
	}

	if (user_modified.size() == 0 && N == 1) {
		cout << "There is 1 account and no account is modified";
	}
	else if (user_modified.size() == 0 && N != 1) {
		cout << "There are " << N << " accounts and no account is modified";
	}
	else {
		cout << user_modified.size() << endl;
		for (int i = 0; i < user_modified.size(); i++) {
			cout << user_modified[i].username << " " << user_modified[i].password << endl;
		}
	}

	return 0;
}