#include <cstdio>
using namespace std;
int color[99999999] = { 0 };
int main() {
	int M, N;
	scanf("%d%d", &M, &N);
	int tmp;
	int opt = -1;
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int i = 0; i < M; i++) {
			scanf("%d", &tmp);
			color[tmp]++;
			if (opt == -1) {
				opt = tmp;
				max = color[tmp];
			}
			else if (color[tmp] > max) {
				max = color[tmp];
				opt = tmp;
			}
		}
	}
	printf("%d", opt);
	return 0;
}