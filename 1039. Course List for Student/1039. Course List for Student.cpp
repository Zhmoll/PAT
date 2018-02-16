#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> course[26*26*26*10];

inline int namehash(char A[]) {
	return  (A[0] - 'A') * 26 * 26 * 10
		+ (A[1] - 'A') * 26 * 10 
		+ (A[2] - 'A') * 10
		+ A[3] - '0'; 
}

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	char tmp_name[5];
	for (int i = 0; i < K; i++) {
		int courseIndex, studentCount;
		scanf("%d%d", &courseIndex, &studentCount);
		for (int j = 0; j < studentCount; j++) {
			scanf("%s", tmp_name);
			course[namehash(tmp_name)].push_back(courseIndex);
		}
	}
	for (int i = 0; i < N; i++) {
		scanf("%s", tmp_name);
		printf("%s %d", tmp_name, course[namehash(tmp_name)].size());
		sort(course[namehash(tmp_name)].begin(), course[namehash(tmp_name)].end());
		for (int j = 0; j < course[namehash(tmp_name)].size(); j++) {
			printf(" %d", course[namehash(tmp_name)][j]);
		}
		printf("\n");
	}
	return 0;
}