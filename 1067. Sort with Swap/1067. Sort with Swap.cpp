#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int N, tmp;
	scanf("%d", &N);
	vector<int> posi(N), num(N);
	set<int> notChecked;
	int count = 0;
	int swap_count = 0;
	int zero_posi;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		posi[tmp] = i;
		num[i] = tmp;
		if (i != tmp) {
			notChecked.insert(tmp);
		}
		else {
			count++;
		}
	}

	while (count != N) {
		int zero_posi = posi[0];
		if (zero_posi != 0) {
			int another = posi[0];
			int another_posi = posi[another];
			swap(num[zero_posi], num[another_posi]);
			swap(posi[0], posi[another]);
			notChecked.erase(another);
			swap_count++;
			count++;
		}
		else {
			if (count == N - 1) break;
			set<int>::iterator it = notChecked.begin();
			it++;
			int another = *it;
			int another_posi = posi[another];
			swap(num[zero_posi], num[another_posi]);
			swap(posi[0], posi[another]);
			swap_count++;
		}
	}

	printf("%d", swap_count);
	return 0;
}