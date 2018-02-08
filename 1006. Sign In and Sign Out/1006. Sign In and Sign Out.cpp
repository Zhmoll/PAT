#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct user {
	string id;
	int start;
	int end;
};

bool cmp_1(user a, user b) {
	return a.start < b.start;
}

bool cmp_2(user a, user b) {
	return a.end > b.end;
}

int main() {
	int M = 0;
	cin >> M;

	vector<user> stu(M);

	string start_str, end_str;
	for (int i = 0; i < M; i++) { //ID_number Sign_in_time Sign_out_time
		cin >> stu[i].id >> start_str >> end_str;
		stu[i].start = stoi(start_str.substr(0, 2)) * 3600 + stoi(start_str.substr(3, 5)) * 60 + stoi(start_str.substr(6, 8));
		stu[i].end = stoi(end_str.substr(0, 2)) * 3600 + stoi(end_str.substr(3, 5)) * 60 + stoi(end_str.substr(6, 8));
	}

	sort(stu.begin(), stu.end(), cmp_1);
	cout << stu[0].id << " ";

	sort(stu.begin(), stu.end(), cmp_2);
	cout << stu[0].id;

	return 0;
}