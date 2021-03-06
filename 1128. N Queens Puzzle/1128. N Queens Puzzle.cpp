#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int times = 0;
	scanf("%d", &times);

	int N = 0, tmp = 0;
	vector<int> vi;

	for (int i = 0; i < times; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &tmp);
			vi.push_back(tmp);
		}

		bool flag = true;
		for (int j = 0; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				if (abs(vi[j] - vi[k]) == abs(j - k) || vi[j] == vi[k]) {
					flag = false;
					goto out;
				}
			}

		}
	out:
		if (flag) printf("YES\n");
		else printf("NO\n");
		vi.clear();
	}

	return 0;
}