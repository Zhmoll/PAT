#include <cstdio>
#include <vector>
using namespace std;

int main() {
	double input[3][3];
	for (int i = 0; i < 3; i++) {
		scanf("%lf %lf %lf", &input[i][0], &input[i][1], &input[i][2]);
	}

	double sum = 1;
	char d[3] = { 'W','T','L' };

	for (int i = 0; i < 3; i++) {
		int posi = 0;
		double input_max = input[i][0];
		for (int j = 1; j <= 2; j++) {
			if (input[i][j] > input_max) {
				input_max = input[i][j];
				posi = j;
			}
		}
		sum *= input_max;
		printf("%c ", d[posi]);
	}
	sum = (sum*0.65 - 1) * 2;
	printf("%.2f", sum);
	return 0;
}