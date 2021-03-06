#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
struct person {
	string name;
	int height;
};

vector<person> people;

bool cmp(person a, person b) {
	if (a.height != b.height) return a.height < b.height;
	else return a.name > b.name;
}

int main() {
	int N, K;
	cin >> N >> K;
	int row_num = N / K;
	int last_row_num = row_num + N % K;
	for (int i = 0; i < N; i++) {
		person tmp;
		cin >> tmp.name >> tmp.height;
		people.push_back(tmp);
	}
	sort(people.begin(), people.end(), cmp);
	int posi = N - 1;
	vector<deque<person>> row(K);
	for (int i = K - 1; i >= 0; i--) {
		if (i != K - 1) {
			// 前几排 row_total
			bool left = false;
			for (int j = 0; j < row_num; j++, posi--, left = !left) {
				if (!left) row[i].push_back(people[posi]);
				else row[i].push_front(people[posi]);
			}
		}
		else {
			// 最后一排
			bool left = false;
			for (int j = 0; j < last_row_num; j++, posi--, left = !left) {
				if (!left) row[i].push_back(people[posi]);
				else row[i].push_front(people[posi]);
			}
		}
	}
	for (int i = row.size() - 1; i >= 0; i--) {
		for (int j = 0; j < row[i].size(); j++) {
			cout << row[i][j].name;
			if (j != row[i].size() - 1)cout << " ";
			else cout << endl;
		}
	}
	return 0;
}