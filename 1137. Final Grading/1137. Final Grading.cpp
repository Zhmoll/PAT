#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct score {
	string name;
	int programme;
	int midterm;
	int finalterm;
	int grade;
	score() {
		programme = 0;
		midterm = -1;
		finalterm = -1;
		grade = 0;
	}
};

bool cmp(score a, score b) {
	if (a.grade != b.grade) return a.grade > b.grade;
	else return a.name < b.name;
}

int main() {
	// first obtain no less than 200 points from the online programming assignments
	// then receive a final grade no less than 60 out of 100
	//  The final grade is calculated by G = (Gmid-termx 40% + Gfinalx 60%) if Gmid-term > Gfinal, or Gfinal will be taken as the final grade G
	int P, M, N;
	// P, the number of students having done the online programming assignments
	// M, the number of students on the mid-term list
	// N, the number of students on the final exam list
	cin >> P >> M >> N;
	map<string, score> list;
	vector<score> result;
	string tmp_name;
	int tmp_score;
	// online programme
	for (int i = 0; i < P; i++) {
		cin >> tmp_name >> tmp_score;
		list[tmp_name].programme = tmp_score;
	}

	// mid-term
	for (int i = 0; i < M; i++) {
		cin >> tmp_name >> tmp_score;
		list[tmp_name].midterm = tmp_score;
	}

	// final-term
	for (int i = 0; i < N; i++) {
		cin >> tmp_name >> tmp_score;
		list[tmp_name].name = tmp_name;
		list[tmp_name].finalterm = tmp_score;
		if (list[tmp_name].programme >= 200) {
			if (list[tmp_name].midterm > tmp_score) {
				list[tmp_name].grade = list[tmp_name].midterm*0.4 + list[tmp_name].finalterm*0.6 + 0.5;
			}
			else {
				list[tmp_name].grade = tmp_score;
			}
			if (list[tmp_name].grade >= 60)
				result.push_back(list[tmp_name]);
		}
	}

	sort(result.begin(), result.end(), cmp);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i].name << " " << result[i].programme << " " << result[i].midterm << " " << result[i].finalterm << " " << result[i].grade << endl;
	}
	return 0;
}