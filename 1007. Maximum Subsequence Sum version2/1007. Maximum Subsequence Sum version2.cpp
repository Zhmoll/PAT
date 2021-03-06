#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> num, dp, left;

int main() {
	int N;
	scanf("%d", &N);
	int tmp, maxsum = -1, maxi = N - 1;
	bool flag = false;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		if (tmp >= 0) flag = true;
		num.push_back(tmp);
		int current_dp;
		if (i != 0) {
			if (tmp > tmp + dp[i - 1]) {
				left.push_back(i);
				current_dp = tmp;
			}
			else {
				left.push_back(left[i - 1]);
				current_dp = tmp + dp[i - 1];
			}
		}
		else {
			current_dp = tmp;
			left.push_back(i);
		}

		if (current_dp > maxsum) {
			maxsum = current_dp;
			maxi = i;
		}
		dp.push_back(current_dp);
	}

	if (!flag)
		printf("0 %d %d", num[0], num[maxi]);
	else
		printf("%d %d %d", maxsum, num[left[maxi]], num[maxi]);
	return 0;
}