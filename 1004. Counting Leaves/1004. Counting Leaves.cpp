#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	vector<vector<int>> node(N + 1);
	for (int i = 0; i < M; i++) {
		int id, K;
		scanf("%d%d", &id, &K);
		for (int j = 0; j < K; j++) {
			int child;
			scanf("%d", &child);
			node[id].push_back(child);
		}
	}

	queue<int> q;
	q.push(1);
	while (1) {
		int currentSize = q.size();
		int thisLevelNoChild = 0;
		for (int i = 0; i < currentSize; i++) {
			int current = q.front();
			q.pop();
			if (node[current].size() == 0) {
				thisLevelNoChild++;
			}
			else {
				for (int j = 0; j < node[current].size(); j++) {
					q.push(node[current][j]);
				}
			}
		}
		printf("%d", thisLevelNoChild);
		if (q.size() != 0) printf(" ");
		else break;
	}

	return 0;
}