#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int num) {
	if (num == 1) return false;
	if (num == 2) return true;
	bool flag = true;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num%i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
}

int main() {
	int N;
	scanf("%d", &N);
	int id;
	vector<int> rank;
	rank.push_back(-1);
	for (int i = 0; i < N; i++) {
		scanf("%d", &id);
		rank.push_back(id);
	}
	int K;
	scanf("%d", &K);
	bool checked[10005] = { false };
	for (int i = 0; i < K; i++) {
		scanf("%d", &id);

		// 寻找
		int found = -1;
		for (int i = 1; i < rank.size(); i++) {
			if (id == rank[i]) {
				found = i;
				break;
			}
		}

		if (found != -1) {
			if (checked[id]) {
				printf("%04d: Checked\n", id);
				continue;
			}

			if (found == 1) {
				printf("%04d: Mystery Award\n", id);
				checked[id] = true;
				continue;
			}

			if (isPrime(found)) {
				printf("%04d: Minion\n", id);
				checked[id] = true;
				continue;
			}
			else {
				printf("%04d: Chocolate\n", id);
				checked[id] = true;
				continue;
			}
		}
		else {
			printf("%04d: Are you kidding?\n", id);
		}
	}

	return 0;
}