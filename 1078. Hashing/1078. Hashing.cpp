#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
bool isPrime(int num) {
	if (num == 1) return false;
	bool flag = true;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num%i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
}

inline int hash_num(int num, int size) {
	return num % size;
}

int main() {
	int MSize, N;
	scanf("%d%d", &MSize, &N);
	while (!isPrime(MSize)) {
		MSize++;
	}
	vector<int> table(MSize);
	fill(table.begin(), table.end(), -1);
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		if (table[hash_num(tmp, MSize)] == -1) {
			table[hash_num(tmp, MSize)] = tmp;
			printf("%d", hash_num(tmp, MSize));
		}
		else {
			int j;
			bool flag = false;
			for (j = 1; j <= MSize; j++) {
				if (table[hash_num(tmp + j * j, MSize)] == -1) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				printf("-");
				if (i != N - 1)printf(" ");
				continue;
			}
			table[hash_num(tmp + j * j, MSize)] = tmp;
			printf("%d", hash_num(tmp + j * j, MSize));
		}
		if (i != N - 1)printf(" ");
	}
	return 0;
}