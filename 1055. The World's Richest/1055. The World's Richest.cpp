#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct person {
	char name[12];
	int age;
	int worth;
};

bool cmp(person &a, person &b) {
	if (a.worth != b.worth) return a.worth > b.worth;
	else if (a.age != b.age) return a.age < b.age;
	else return strcmp(a.name, b.name) < 0;
}

vector<person> input, filter;

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		person a;
		scanf("%s %d %d", a.name, &a.age, &a.worth);
		input.push_back(a);
	}
	sort(input.begin(), input.end(), cmp);
	int age_count[202] = { 0 };
	for (int i = 0; i < N; i++) {
		age_count[input[i].age]++;
		if (age_count[input[i].age] <= 100) {
			filter.push_back(input[i]);
		}
	}

	int M, Left, Right;
	for (int i = 0; i < K; i++) {
		scanf("%d%d%d", &M, &Left, &Right);
		printf("Case #%d:\n", i + 1);
		int count = 0;
		for (int j = 0; j < filter.size() && count < M; j++) {
			if (filter[j].age >= Left && filter[j].age <= Right) {
				printf("%s %d %d\n", filter[j].name, filter[j].age, filter[j].worth);
				count++;
			}
		}
		if (count == 0) printf("None\n");
	}
	return 0;
}