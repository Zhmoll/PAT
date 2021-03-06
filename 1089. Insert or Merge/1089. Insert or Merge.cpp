#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> input, result_arr;
vector<int> sort_arr, tmp_arr;

bool isInsertionSort() {
	for (int i = 1; i < sort_arr.size(); i++) {
		int j = i;
		while (j > 0 && sort_arr[j] < sort_arr[j - 1]) {
			swap(sort_arr[j], sort_arr[j - 1]);
			j--;
		}
		if (sort_arr == result_arr) {
			j = i + 1;
			while (j > 0 && sort_arr[j] < sort_arr[j - 1]) {
				swap(sort_arr[j], sort_arr[j - 1]);
				j--;
			}
			return true;
		}
	}
	return false;
}

int main() {
	int N;
	scanf("%d", &N);
	input.resize(N);
	result_arr.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &result_arr[i]);
	}
	sort_arr = input;
	if (isInsertionSort()) {
		printf("Insertion Sort\n");
		for (int i = 0; i < sort_arr.size(); i++) {
			printf("%d", sort_arr[i]);
			if (i != sort_arr.size() - 1) printf(" ");
		}
	}
	else {
		printf("Merge Sort\n");
		sort_arr = input;

		int step = 1;
		int posi;
		while (step <= N) {
			posi = 0;
			while (posi + step * 2 <= N) {
				sort(sort_arr.begin() + posi, sort_arr.begin() + posi + step * 2);
				posi = posi + step * 2;
			}
			int rest = N - posi;
			if (rest > 0) {
				sort(sort_arr.begin() + posi, sort_arr.begin() + posi + rest);
			}
			step *= 2;
			if (sort_arr == result_arr) {
				posi = 0;
				while (posi + step * 2 <= N) {
					sort(sort_arr.begin() + posi, sort_arr.begin() + posi + step * 2);
					posi = posi + step * 2;
				}
				int rest = N - posi;
				if (rest > 0) {
					sort(sort_arr.begin() + posi, sort_arr.begin() + posi + rest);
				}
				break;
			}
		}

		for (int i = 0; i < sort_arr.size(); i++) {
			printf("%d", sort_arr[i]);
			if (i != sort_arr.size() - 1) printf(" ");
		}
	}


	return 0;
}