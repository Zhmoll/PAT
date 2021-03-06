#include <cstdio>
#include <cstdlib>

int P[105] = { 0 };	// 排列
int hashTable[105] = { false };	// hash
int right = 0; // 右边界
void genP(int index) {
	// 递归基
	if (index == right + 1) {
		for (int i = 1; i <= right; i++) {
			printf("%d", P[i]);
		}
		printf("\n");
		return;
	}

	// 递归式
	for (int x = 1; x <= right; x++) {
		if (!hashTable[x]) {
			P[index] = x;
			hashTable[x] = true;
			genP(index + 1);
			hashTable[x] = false;
		}
	}
}

int main() {
	scanf("%d", &right);
	genP(1);

	system("pause");
	return 0;
}