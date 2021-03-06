#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> seq1, seq2;

int main() {
	int N1, N2;
	long long tmp;
	scanf("%d", &N1);
	for (int i = 0; i < N1; i++) {
		scanf("%lld", &tmp);
		seq1.push_back(tmp);
	}
	scanf("%d", &N2);
	for (int i = 0; i < N2; i++) {
		scanf("%lld", &tmp);
		seq2.push_back(tmp);
	}

	int cnt = 0;
	int middle = ((N1 + N2) % 2 == 0) ? (N1 + N2) / 2 : (N1 + N2 + 1) / 2;
	int i = 0, j = 0;
	while (i < N1 && j < N2) {
		if (seq1[i] < seq2[j]) tmp = seq1[i++];
		else tmp = seq2[j++];
		cnt++;
		if (cnt == middle) {
			printf("%lld", tmp);
			return 0;
		}

	}
	while (i < N1) {
		tmp = seq1[i++];
		cnt++;
		if (cnt == middle) {
			printf("%lld", tmp);
			return 0;
		}
	}
	while (j < N2) {
		tmp = seq2[j++];
		cnt++;
		if (cnt == middle) {
			printf("%lld", tmp);
			return 0;
		}
	}
	return 0;
}