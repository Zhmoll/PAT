#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> OneCount;

int oneCount(int num) {
	int count = 0;
	while (num != 0) {
		int digi = num % 10;
		if (digi == 1) {
			count++;
		}
		num /= 10;
	}
	return count;
}

int main() {
	int N;
	cin >> N;
	OneCount.resize(N + 1);
	OneCount[0] = 0;
	OneCount[1] = 1;
	for (int i = 2; i <= N; i++) {
		OneCount[i] = OneCount[i - 1] + oneCount(i);
	}
	printf("%d", OneCount[N]);
	return 0;
}