#include <cstdio>
#include <cmath>

int main() {
	double game[3][3];
	int large[3] = { 0 };
	double tmp_max = 0;
	for (int i = 0; i < 3; i++) {
		scanf("%lf %lf %lf", &game[i][0], &game[i][1], &game[i][2]);
		
		for (int j = 0; j < 3; j++) {
			if (game[i][j] > tmp_max) {
				tmp_max = game[i][j];
				large[i] = j;
			}
		}
		tmp_max = 0;
	}

	double sum = 1;

	for (int i = 0; i < 3; i++) {
		switch (large[i]) {
		case 0: {
			printf("W ");
			sum *= game[i][0];
			break;
		}
		case 1: {
			printf("T ");
			sum *= game[i][1];
			break;
		}
		case 2: {
			printf("L ");
			sum *= game[i][2];
			break;
		}
		}
	}

	sum = (sum*0.65 - 1) * 2;
	printf("%.2f", sum);

	return 0;
}