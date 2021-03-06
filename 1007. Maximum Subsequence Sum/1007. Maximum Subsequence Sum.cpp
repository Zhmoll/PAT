#include <vector>
#include <cstdio>

using namespace std;

int main() {
	int K = 0;
	scanf("%d", &K);

	vector<int> vi;

	int posiLeft = 0;
	int posiRight = 0;
	int sum = -1;

	int newPosiLeft = 0;
	int newPosiRight = 0;
	int current_sum = 0;

	int tmp = 0;
	for (int i = 0; i < K; i++) {
		scanf("%d", &tmp);
		vi.push_back(tmp);

		if (tmp >= 0) {
			// 拿到非负数就纳入序列中
			current_sum += tmp;
			newPosiRight = i;
			if (current_sum > sum) {
				posiLeft = newPosiLeft;
				posiRight = newPosiRight;
				sum = current_sum;
			}
		}
		else {
			// 试探性
			current_sum += tmp;
			if (current_sum < 0) {
				// 新序列左端应从下一个数开始
				newPosiLeft = i + 1;
				current_sum = 0;
			}
		}
	}
	if (sum >= 0)
		printf("%d %d %d", sum, vi[posiLeft], vi[posiRight]);
	else
		printf("%d %d %d", 0, vi[0], vi[K - 1]);
	return 0;
}
