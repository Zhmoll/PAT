#include <cstdio>
#include <map>
#include <vector>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	map<int, int> count;
	vector<int> input;
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		input.push_back(tmp);
		count[tmp]++;
	}

	int winner = -1;
	for (int i = 0; i < N; i++) {
		if (count[input[i]] == 1) {
			winner = input[i];
			break;
		}
	}
	if (winner == -1) {
		printf("None");
	}
	else {
		printf("%d", winner);
	}

	return 0;
}