#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct person {
	char name[12];
	int age;
	int worth;
};

bool cmp(person a, person b) {
	if (a.worth != b.worth)	return a.worth > b.worth;
	else if (a.age != b.age) return a.age < b.age;
	else return strcmp(a.name, b.name) < 0;
}

int main() {

	int N = 0;// 总人数
	int K = 0;// 查询次数
	scanf("%d %d", &N, &K);

	vector<person> vi;

	for (int i = 0; i < N; i++) {
		person tmp;
		scanf("%s %d %d", tmp.name, &(tmp.age), &(tmp.worth));
		vi.push_back(tmp);
	}

	sort(vi.begin(), vi.end(), cmp);

	for (int i = 0; i < K; i++) {
		int M;// 选取人数
		int ageLeft;
		int ageRight;
		scanf("%d %d %d", &M, &ageLeft, &ageRight);

		printf("Case #%d:\n", i+1);
		bool flag = false;
		for (int j = 0, max = 0; j < N && max < M; j++) {
			if (vi[j].age >= ageLeft && vi[j].age <= ageRight) {
				printf("%s %d %d\n", vi[j].name, vi[j].age, vi[j].worth);
				flag = true;
				max++;
			}
		}
		if (!flag) printf("None\n");
	}

	return 0;
}