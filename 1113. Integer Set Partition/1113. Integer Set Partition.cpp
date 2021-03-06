#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	vector<int> num;
	int N;
	scanf("%d", &N);
	int tmp;
	long long sum1 = 0, sum2 = 0, diff = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		num.push_back(tmp);
	}
	sort(num.begin(), num.end());
	if (N % 2 == 0) {
		// 偶数
		printf("0 ");
	}
	else {
		// 奇数
		printf("1 ");
	}
	vector<int>::iterator it = num.begin();
	for (int i = 0; i < N / 2; i++) {
		sum1 += *it;
		it++;
	}
	for (int i = N / 2; i < N; i++) {
		sum2 += *it;
		it++;
	}
	diff = sum2 - sum1;
	printf("%lld", diff);

	return 0;
}