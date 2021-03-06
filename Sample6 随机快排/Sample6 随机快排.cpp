#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
int Partition(int A[], int left, int right) {
	int p = round(1.0*rand() / RAND_MAX * (right - left) + left);
	swap(A[p], A[left]);
	int temp = A[left];
	while (left < right) {
		while (left < right && A[right] > temp) right--;
		A[left] = A[right];
		while (left < right && A[left] <= temp) left++;
		A[right] = A[left];
	}
	A[left] = temp;
	return left;
}

void quickSort(int A[], int left, int right) {
	if (left < right) {
		int posi = Partition(A, left, right);
		quickSort(A, left, posi - 1);
		quickSort(A, posi + 1, right);
	}
}

int randSelect(int A[], int left, int right, int K) {
	if (left == right) return A[left];
	int p = Partition(A, left, right);
	int M = p - left + 1; // A[p]是第M大
	if (M == K) return A[p];
	else if (K < M) {
		return randSelect(A, left, p - 1, K);
	}
	else {
		return randSelect(A, p + 1, right, K - M);
	}
}

int main() {
	srand((unsigned)time(NULL));
	
	return 0;
}