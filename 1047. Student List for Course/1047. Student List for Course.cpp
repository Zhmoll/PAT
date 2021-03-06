#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
inline int hash_name(char name[]) {
	return (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 + (name[2] - 'A') * 10 + (name[3] - '0');
}

inline void to_name(int index, char name[]) {
	name[0] = index / (26 * 26 * 10) + 'A';
	index = index % (26 * 26 * 10);
	name[1] = index / (26 * 10) + 'A';
	index = index % (26 * 10);
	name[2] = index / 10 + 'A';
	index = index % 10;
	name[3] = index + '0';
}

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	vector<vector<int>> course(K + 1);
	char name[10];
	int M, tmp;
	for (int i = 0; i < N; i++) {
		scanf("%s %d", name, &M);
		for (int j = 0; j < M; j++) {
			scanf("%d", &tmp);
			course[tmp].push_back(hash_name(name));
		}
	}
	for (int i = 1; i < course.size(); i++) {
		printf("%d %d\n", i, course[i].size());
		sort(course[i].begin(), course[i].end());
		for (int j = 0; j < course[i].size(); j++) {
			int index = course[i][j];
			to_name(index, name);
			printf("%s\n",name);
		}
	}
	return 0;
}