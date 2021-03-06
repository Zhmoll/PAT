#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;
vector<int> input;
vector<int> leftsum;
int main() {
	int N, M, sum = 0, tmp;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		input.push_back(tmp);
		sum += tmp;
		leftsum.push_back(sum);
	}

	vector<int> equal_ans, more_ans;
	int min = INF;
	for (int i = 0; i < N; i++) {
		vector<int>::iterator it = lower_bound(leftsum.begin(), leftsum.end(), M + leftsum[i] - input[i]);
		int j = it - leftsum.begin();
		if (j < N && leftsum[j] - leftsum[i] + input[i] == M) {
			equal_ans.push_back(i + 1);
			equal_ans.push_back(j + 1);
		}
		else if (j < N && leftsum[j] - leftsum[i] + input[i] > M) {
			if (leftsum[j] - leftsum[i] + input[i] < min) {
				more_ans.clear();
				more_ans.push_back(i + 1);
				more_ans.push_back(j + 1);
				min = leftsum[j] - leftsum[i] + input[i];
			}
			else if (leftsum[j] - leftsum[i] + input[i] == min) {
				more_ans.push_back(i + 1);
				more_ans.push_back(j + 1);
			}
		}
	}

	int size = equal_ans.size();
	if (size > 0) {
		for (int i = 0; i < size; i += 2) {
			printf("%d-%d\n", equal_ans[i], equal_ans[i + 1]);
		}
	}
	else {
		size = more_ans.size();
		for (int i = 0; i < size; i += 2) {
			printf("%d-%d\n", more_ans[i], more_ans[i + 1]);
		}
	}
	return 0;
}