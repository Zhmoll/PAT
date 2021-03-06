#include <cstdio>
#include <vector>
using namespace std;

vector<int> initial;
vector<int> partial;
bool isHeapSort = false;

void downAdjust(int lo, int hi) {
	int i = lo, j = lo * 2;
	while (j <= hi) {
		if (j + 1 <= hi && initial[j] < initial[j + 1]) {
			j = j + 1;
		}
		if (initial[i] < initial[j]) {
			swap(initial[i], initial[j]);
			i = j;
			j = i * 2;
		}
		else {
			break;
		}
	}
}

void createHeap() {
	for (int i = (initial.size() - 1) / 2; i >= 1; i--) {
		downAdjust(i, initial.size() - 1);
	}
}

void heapSort() {
	createHeap();
	for (int i = initial.size() - 1; i > 1; i--) {
		swap(initial[1], initial[i]);
		downAdjust(1, i - 1);
		if (initial == partial) {
			isHeapSort = true;
			swap(initial[1], initial[i - 1]);
			downAdjust(1, i - 2);
			break;
		}
	}
}

void insertionSort() {
	for (int i = 2; i < initial.size(); i++) {
		int point = i;
		while (initial[point] < initial[point - 1] && point > 1) {
			swap(initial[point], initial[point - 1]);
			point--;
		}
		if (initial == partial) {
			int point = i + 1;
			while (initial[point] < initial[point - 1] && point > 1) {
				swap(initial[point], initial[point - 1]);
				point--;
			}
			break;
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);
	vector<int> input(N + 1);
	initial.resize(N + 1);
	partial.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &input[i]);
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &partial[i]);
	}
	initial = input;

	heapSort();
	if (isHeapSort) {
		printf("Heap Sort\n");
		for (int i = 1; i < initial.size(); i++) {
			printf("%d", initial[i]);
			if (i != initial.size() - 1) printf(" ");
		}
	}
	else {
		initial = input;
		printf("Insertion Sort\n");
		insertionSort();
		for (int i = 1; i < initial.size(); i++) {
			printf("%d", initial[i]);
			if (i != initial.size() - 1) printf(" ");
		}
	}

	return 0;
}