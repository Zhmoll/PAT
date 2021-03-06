#include <cstdio>
#include <vector>
using namespace std;
double P, r;
vector<vector<int>> node;
vector<bool> isRetailer;
vector<int> amount;
double total = 0;

double binaryPow(double a, int b) {
	double ans = 1;
	while (b > 0) {
		if (b & 1) {
			ans = ans * a;
		}
		a *= a;
		b >>= 1;
	}
	return ans;
}

void DFS(int current, int level) {
	if (node[current].size() == 0) {
		if (isRetailer[current]) {
			double sum = amount[current] * P;
			double g = 1 + r / 100;
			total += binaryPow(g, level) * sum;
		}
		return;
	}

	for (int i = 0; i < node[current].size(); i++) {
		DFS(node[current][i], level + 1);
	}
}

int main() {
	int N;
	scanf("%d%lf%lf", &N, &P, &r);
	node.resize(N);
	isRetailer.resize(N);
	amount.resize(N);
	int K, tmp;
	for (int i = 0; i < node.size(); i++) {
		scanf("%d", &K);
		for (int j = 0; j < K; j++) {
			scanf("%d", &tmp);
			node[i].push_back(tmp);
		}
		if (K == 0) {
			isRetailer[i] = true;
			scanf("%d", &tmp);
			amount[i] = tmp;
		}
	}
	DFS(0, 0);
	printf("%.1f", total);
	return 0;
}