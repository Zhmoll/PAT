#include <cstdio>

int binary_search(int A[], int left, int right, int x) {
	int mid;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (A[mid] == x) return mid;
		else if (A[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}

int lower_bound(int A[], int left, int right, int x) {
	int mid;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (A[mid] >= x) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}

int upper_bound(int A[], int left, int right, int x) {
	int mid;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (A[mid] > x) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
}

//int solve(int left, int right) {
//	int mid;
//	while (left < right) {
//		mid = (left + right) / 2;
//		if (条件成立) { // 条件成立，第一个满足条件的元素的位置<=mid
//			right = mid;
//		}
//		else { // 条件不成立，第一个满足该条件的元素的位置>mid
//			left = mid + 1;
//		}
//	}
//	return left;
//}