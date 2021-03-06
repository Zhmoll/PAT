#include <cstdio>
#include <map>
#include <queue>
#include <functional>
#include <set>
using namespace std;
int main() {
	int N = 0, M = 0;
	scanf("%d", &N);

	map<int, int> couple;
	int tmp1, tmp2;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &tmp1, &tmp2);
		couple[tmp1] = tmp2;
		couple[tmp2] = tmp1;
	}

	scanf("%d", &M);
	int tmp3;
	set<int> single, wait;
	for (int i = 0; i < M; i++) {
		scanf("%d", &tmp3);
		if (!couple[tmp3] && couple[tmp3] != 0) {
			single.insert(tmp3);
		}
		else {
			set<int>::iterator res = wait.find(tmp3);
			if (res != wait.end()) {
				// 老伴等到
				single.erase(couple[*res]);
				wait.erase(res);
			}
			else {
				single.insert(tmp3);
				wait.insert(couple[tmp3]);
			}
		}
	}

	printf("%d\n", single.size());
	set<int>::iterator it = single.begin();
	for (int i = 0; i < single.size(); i++, it++) {
		printf("%05d", *it);
		if (i != single.size() - 1) printf(" ");
	}
	return 0;
}