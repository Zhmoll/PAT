#include <cstdio>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
	int N, M, Q;
	scanf("%d%d", &N, &M);

	map<int, set<int>> edge;

	int e1, e2;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &e1, &e2);
		edge[e1].insert(e2);
		edge[e2].insert(e1);
	}

	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		int total = 0;
		scanf("%d", &total);
		bool flag = true;
		vector<int> path(total);
		vector<int> v_count(N+1);
		for (int i = 0; i < total; i++) {
			scanf("%d", &path[i]);
			if (i != total - 1) v_count[path[i]]++;
		}
		// 处理
		// 1.点数不对
		if (total != N + 1) {
			flag = false;
		}
		// 2.首尾不相同
		if (path[0] != path[total - 1]) {
			flag = false;
		}
		// 3.出现重复点、没出现点
		for (int i = 1; i <= N; i++) {
			if (v_count[i] != 1) {
				flag = false;
				break;
			}
		}
		// 4.与路径不符合
		vector<int>::iterator it = path.begin();
		int last = *it;
		it++;
		for (; it != path.end(); last = *it, it++) {
			if (edge[last].find(*it) == edge[last].end()) {
				// 没找到
				flag = false;
				break;
			}
		}
		if (!flag) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}

	return 0;
}
