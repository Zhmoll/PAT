#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int N, K, P;
vector<int> pow_p;
vector<int> tmp_path, path;
int opt_factorsum = 0;
int tmp_sum = 0;
void DFS(int index, int current, int sum, int factor_sum) {
	if (index == K) {
		if (sum == N) {
			if (factor_sum > opt_factorsum) {
				opt_factorsum = factor_sum;
				path = tmp_path;
			}
		}
		return;
	}
	if (current < 1 || sum >= N)return;
	tmp_path.push_back(current);
	DFS(index + 1, current, sum + pow_p[current], factor_sum + current);
	tmp_path.pop_back();
	DFS(index, current - 1, sum, factor_sum);
}

int main() {
	scanf("%d%d%d", &N, &K, &P);
	pow_p.push_back(0);
	for (int i = 1; pow_p.back() < N; i++)
		pow_p.push_back(pow(i, P));

	DFS(0, pow_p.size() - 1, 0, 0);

	if (opt_factorsum == 0)
		printf("Impossible");
	else {
		printf("%d = ", N);
		for (int i = 0; i < path.size(); i++) {
			printf("%d^%d", path[i], P);
			if (i != path.size() - 1) printf(" + ");
		}
	}
	return 0;
}