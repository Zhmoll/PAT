#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
// p149 不知为何会超时
int input[100005];

int randPartition(int vi[], int left, int right) {
	int rand_posi = round(1.0*rand() / RAND_MAX * (right - left) + left);
	swap(vi[left], vi[rand_posi]);
	int tmp = vi[left];
	while (left < right) {
		while (left < right && vi[right] > tmp) right--;
		vi[left] = vi[right];
		while (left < right && vi[left] <= tmp) left++;
		vi[right] = vi[left];
	}
	vi[left] = tmp;
	return left;
}

void randSelect(int vi[], int left, int right, int K) {
	if (right == left) return;
	int current = randPartition(vi, left, right);
	int M = current - left + 1;
	if (K == M) return;
	else if (K < M) randSelect(vi, left, current - 1, K);
	else randSelect(vi, current + 1, right, K - M);
}

int main() {
	srand((unsigned)time(NULL));
	int N, sum = 0, sum1 = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);
		sum += input[i];
	}
	randSelect(input, 0, N - 1, N / 2);
	for (int i = 0; i < N / 2; i++) {
		sum1 += input[i];
	}
	printf("%d %d", !(N % 2 == 0), sum - sum1 - sum1);
	return 0;
}