#include <cstdio>
#include <cstdlib>
#include <cmath>

int main() {
	int N = 0;
	scanf("%d", &N);
	int sum = 0;
	int current = 0;
	int floor = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &floor);
		if (floor - current > 0) { // up
			sum += (floor - current) * 6;
		}
		else if (floor - current < 0) { // down
			sum += (current - floor) * 4;
		}
		sum += 5;
		current = floor;
	}

	printf("%d", sum);

	system("pause");
	return 0;
}