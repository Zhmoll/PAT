#include <cstdio>
#include <set>
using namespace std;
int main() {
	int N, tmp;
	scanf("%d", &N);
	set<int> friendId;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		int frinum = 0;
		while (tmp != 0) {
			frinum += tmp % 10;
			tmp /= 10;
		}
		friendId.insert(frinum);
	}
	printf("%d\n", friendId.size());
	set<int>::iterator it = friendId.begin();
	for (int i = 0; i < friendId.size(); i++, it++) {
		printf("%d", *it);
		if (i != friendId.size() - 1) printf(" ");
	}
	return 0;
}