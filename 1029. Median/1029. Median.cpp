#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<long long> seq;
	int N1, N2;
	scanf("%d", &N1);
	long long tmp;
	for (int i = 0; i < N1; i++) {
		scanf("%lld", &tmp);
		seq.push_back(tmp);
	}
	scanf("%d", &N2);
	for (int i = 0; i < N2; i++) {
		scanf("%lld", &tmp);
		seq.push_back(tmp);
	}
	sort(seq.begin(), seq.end());

	int length = N1 + N2;
	int middle;
	if (length % 2 == 0) {
		middle = length / 2 - 1;
	}
	else {
		middle = length / 2;
	}
	printf("%lld", seq[middle]);

	return 0;
}