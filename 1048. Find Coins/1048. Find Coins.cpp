#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> coin;
vector<int> input;
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	coin.resize(505);
	fill(coin.begin(), coin.end(), 0);
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		input.push_back(tmp);
		coin[tmp]++;
	}
	sort(input.begin(), input.end());
	bool flag = false;
	for (int i = 0; i < input.size(); i++) {
		int one = input[i];
		int another = M - one;
		if (another > 0 && coin[another] > 0) {
			if (another != one) {
				printf("%d %d", one, another);
				flag = true;
				break;
			}
			else if (coin[another] > 1) {
				printf("%d %d", one, another);
				flag = true;
				break;
			}
		}
		else if (another <= 0) {
			break;
		}
	}
	if (!flag)
		printf("No Solution");
	return 0;
}