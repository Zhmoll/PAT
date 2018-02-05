#include <cstdio>
#include <cstdlib>
#include <cstring>

struct stu {
	char name[15];
	char gender;
	char id[15];
	int grade;
};

int main() {
	int N = 0;
	scanf("%d", &N);

	stu temp, male, female;
	bool hasMale = false, hasFemale = false;
	for (int i = 0; i < N; i++) {
		scanf("%s %c %s %d", &temp.name, &temp.gender, &temp.id, &temp.grade);
		if (temp.gender == 'M') {
			if (!hasMale) {
				male = temp;
				hasMale = true;
			}
			else if (temp.grade < male.grade) {
				male = temp;
			}
		}
		else if (temp.gender == 'F') {
			if (!hasFemale) {
				female = temp;
				hasFemale = true;
			}
			else if (temp.grade > female.grade) {
				female = temp;
			}
		}
	}


	if (hasFemale)
		printf("%s %s\n", female.name, female.id);
	else
		printf("Absent\n");
	if (hasMale)
		printf("%s %s\n", male.name, male.id);
	else
		printf("Absent\n");
	if (hasMale && hasFemale)
		printf("%d", female.grade - male.grade);
	else
		printf("NA");

	system("pause");
	return 0;
}