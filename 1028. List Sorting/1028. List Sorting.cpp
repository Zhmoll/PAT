#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct student {
	int id;//a 6-digit number
	char name[10];
	int grade;
}stu[100005];

int C = 0;// sort column

bool cmp(student a, student b) {
	if (C == 1) {
		return a.id < b.id;
	}
	else if (C == 2) {
		int res = strcmp(a.name, b.name);
		if (res == 0) return a.id < b.id;
		return res < 0;
	}
	else if (C == 3) {
		if (a.grade == b.grade) return a.id < b.id;
		return a.grade < b.grade;
	}
}

int main() {

	int N = 0;// N<e5

	scanf("%d%d", &N, &C);

	for (int i = 0; i < N; i++) {
		scanf("%d %s %d", &stu[i].id, &stu[i].name, &stu[i].grade);
	}

	sort(stu, stu + N, cmp);

	for (int i = 0; i < N; i++) {
		printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
	}

	system("pause");
	return 0;
}