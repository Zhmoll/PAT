#include <cstdio>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	vector<set<int>> node(105);
	for (int i = 0; i < M; i++) {
		int id, K;
		scanf("%d %d", &id, &K);
		int tmp;
		for (int j = 0; j < K; j++) {
			scanf("%d", &tmp);
			node[id].insert(tmp);
		}
	}

	queue<int> q;
	q.push(1);
	int maxLevelSize = 0, maxLevel = 0, currentLevel = 1;
	while (q.size() != 0) {
		int currentLevelSize = q.size();
		if (currentLevelSize > maxLevelSize) {
			maxLevelSize = currentLevelSize;
			maxLevel = currentLevel;
		}
		for (int i = 0; i < currentLevelSize; i++) {
			int current = q.front();
			q.pop();
			set<int>::iterator setit = node[current].begin();
			for (; setit != node[current].end(); setit++) {
				q.push(*setit);
			}
		}
		currentLevel++;
	}
	printf("%d %d", &maxLevelSize, &maxLevel);
	return 0;
}