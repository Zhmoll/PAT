#include <cstdio>
#include <set>
using namespace std;

int hash_to(char name[]) {
	return (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 + (name[2] - 'A') * 10 + (name[3] - '0');
}
set<int> stu[26 * 26 * 26 * 10 + 5];
int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	int c, d;
	char name[10];
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &c, &d);
		for (int j = 0; j < d; j++) {
			scanf("%s", name);
			stu[hash_to(name)].insert(c);
		}
	}

	for (int i = 0; i < N; i++) {
		scanf("%s", name);
		set<int> &s = stu[hash_to(name)];
		printf("%s %d", name, s.size());
		for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
			printf(" %d", *it);
		}
		printf("\n");
	}
	return 0;
}