#include <cstdio>
#include <map>
#include <set>
#include <string>
using namespace std;
int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	map<string, set<int>> student;
	char tmp_name[5];
	for (int i = 0; i < K; i++) {
		int courseIndex, studentCount;
		scanf("%d%d", &courseIndex, &studentCount);
		for (int j = 0; j < studentCount; j++) {
			scanf("%s", tmp_name);
			student[tmp_name].insert(courseIndex);
		}
	}
	for (int i = 0; i < N; i++) {
		scanf("%s", tmp_name);
		printf("%s %d", tmp_name, student[tmp_name].size());
		set<int>::iterator it = student[tmp_name].begin();
		for (int j = 0; j < student[tmp_name].size(); j++, it++) {
			printf(" %d", *it);
		}
		printf("\n");
	}
	return 0;
}