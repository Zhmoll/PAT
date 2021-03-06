#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> input;
int main() {
	int N, p, tmp;
	scanf("%d%d", &N, &p);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		input.push_back(tmp);
	}
	sort(input.begin(), input.end());

	int ans = 0; 
	for (int i = 0; i < N; i++) { // 二分
		vector<int>::iterator it = upper_bound(input.begin() + i, input.end(), (long long)input[i] * p);
		int j = it - input.begin();
		ans = max(ans, j - i);
	}
	//int left = 0, right = 0; // two pointers
	//while (left < N&&right < N) {
	//	while (right < N && input[right] <= (long long)input[left] * p) right++;
	//	ans = max(ans, right - left);
	//	left++;
	//}
	printf("%d", ans);
	return 0;
}