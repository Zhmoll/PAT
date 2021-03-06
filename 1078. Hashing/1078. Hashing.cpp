#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
bool isPrime(int a) {
	if (a == 0 || a == 1) return false;
	bool flag = true;
	for (int i = 2; i <= sqrt(a); i++) {
		if (a%i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
}

int tohash(int key, int TSize) {
	return key % TSize;
}

int main() {
	int MSize, N, tmp;
	scanf("%d%d", &MSize, &N);
	while (!isPrime(MSize)) MSize++;
	vector<int> vi(MSize, -1);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		int posi, x = 0;
		do {
			posi = tohash(tmp + x * x, MSize);
			x++;
		} while (vi[posi] != -1 && x <= MSize);

		if (vi[posi] == -1) {
			printf("%d", posi);
			vi[posi] = tmp;
		}
		else {
			printf("-");
		}

		if (i != N - 1) printf(" ");
	}
	return 0;
}