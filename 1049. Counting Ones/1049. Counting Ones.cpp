#include <iostream>
using namespace std;
int main() {
	int wei = 1;
	int left, right, current;
	int N;
	int answer = 0;
	scanf("%d", &N);

	while (N / wei != 0) {
		left = N / (wei * 10);
		right = N % wei;
		current = N / wei % 10;

		if (current == 0) {
			answer += left * wei;
		}
		else if (current == 1) {
			answer += left * wei + right + 1;
		}
		else {
			answer += (left + 1)*wei;
		}
		wei *= 10;
	}
	printf("%d", answer);
	return 0;
}