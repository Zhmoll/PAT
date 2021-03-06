#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	vector<int> input(N);
	vector<int> posi(N);
	int not_posi_cnt = 0;
	int max_not_posi = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);
		posi[input[i]] = i;
		if (i != input[i]) {
			not_posi_cnt++;
			max_not_posi = i;
		}
	}

	int swap_cnt = 0;
	while (not_posi_cnt > 0 && max_not_posi != 0) {
		int zero_posi = posi[0];
		if (zero_posi == 0) {
			// 零归位了
			int max_not = input[max_not_posi];
			while (max_not_posi>0 && input[max_not_posi] == max_not_posi) {
				max_not_posi--;
				max_not = input[max_not_posi];
			}
			if (max_not_posi == 0) break;
			swap(input[zero_posi], input[max_not_posi]);
			swap(posi[0], posi[max_not]);
			swap_cnt++;
		}
		else {
			// 与零位置交换
			int another = zero_posi;
			int another_posi = posi[another];
			swap(input[zero_posi], input[another_posi]);
			swap(posi[0], posi[another]);
			swap_cnt++;
			not_posi_cnt--;
		}
	}
	printf("%d", swap_cnt);
	return 0;
}