#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, p;
	scanf("%d%d", &N, &p);

	int tmp;
	vector<int> sequence;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		sequence.push_back(tmp);
	}

	sort(sequence.begin(), sequence.end());

	int length = 0;
	for (int i = 0; i < sequence.size(); i++) {
		long long min = sequence[i], tmp;
		for (int j = i + length; j < sequence.size(); j++) {
			long long max = sequence[j];
			tmp = p * min;
			if (max <= tmp) {
				if (j - i + 1 > length) {
					length = j - i + 1;
				}
			}
			else {
				break;
			}
		}
	}

	printf("%d", length);
	return 0;
}