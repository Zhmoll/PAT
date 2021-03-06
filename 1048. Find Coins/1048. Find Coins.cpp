// 21点42分
#include <cstdio>
#include <vector>
#define INF 1000000000
using namespace std;
int coin[100005] = { 0 };
int main() {
	int N, M, tmp;
	scanf("%d%d", &N, &M);
	int small = INF;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		coin[tmp]++;
		if (coin[M - tmp] > 0 && M != tmp * 2 || coin[M - tmp] >= 2) {
			if (tmp < M - tmp) {
				if (tmp < small)
					small = tmp;
			}
			else {
				if (M - tmp < small)
					small = M - tmp;
			}
		}
	}
	if (small != INF)
		printf("%d %d", small, M - small);
	else
		printf("No Solution");
	return 0;
}