#include <cstdio>
#include <cstring>
#define INF 1000000000
int main() {
	int N;
	scanf("%d", &N);
	char name[20];
	char gender;
	char id[20];
	int grade;

	char male_name[20], female_name[20], male_id[20], female_id[20];
	int male_grade = INF, female_grade = -1;
	for (int i = 0; i < N; i++) {
		scanf("%s %c %s %d", name, &gender, id, &grade);
		if (gender == 'M') {
			if (grade < male_grade) {
				male_grade = grade;
				strcpy(male_name, name);
				strcpy(male_id, id);
			}
		}
		else {
			if (grade > female_grade) {
				female_grade = grade;
				strcpy(female_name, name);
				strcpy(female_id, id);
			}
		}
	}
	if (female_grade != -1) {
		printf("%s %s\n", female_name, female_id);
	}
	else {
		printf("Absent\n");
	}
	if (male_grade != INF) {
		printf("%s %s\n", male_name, male_id);
	}
	else {
		printf("Absent\n");
	}
	if (male_grade == INF || female_grade == -1) {
		printf("NA");
	}
	else {
		printf("%d", female_grade - male_grade);
	}
	return 0;
}