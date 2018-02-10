#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<int> num(N + 1);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &num[i]);
	}
	sort(num.begin() + 1, num.end());

	int Edin = 0;
	for (int i = 1; i <= N; i++) {
		if (num[N - i + 1] > i)
			Edin = i;
	}
	printf("%d", Edin);
	return 0;
}