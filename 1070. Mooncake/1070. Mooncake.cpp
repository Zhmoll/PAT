#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct Mooncake {
	double inventory;
	double total_price;
};
bool cmp(Mooncake &a, Mooncake &b) {
	return a.total_price / a.inventory > b.total_price / b.inventory;
}
int main() {
	int N;
	double D;
	scanf("%d %lf", &N, &D);
	vector<Mooncake> cake(N);
	for (int i = 0; i < N; i++) {
		scanf("%lf", &(cake[i].inventory));
	}
	for (int i = 0; i < N; i++) {
		scanf("%lf", &(cake[i].total_price));
	}
	sort(cake.begin(), cake.end(), cmp);
	double sum = 0;
	for (int i = 0; i < N; i++) {
		if (cake[i].inventory <= D) {
			D -= cake[i].inventory;
			sum += cake[i].total_price;
			if (D == 0) break;
		}
		else {
			sum += cake[i].total_price / cake[i].inventory * D;
			break;
		}
	}
	printf("%.2f", sum);
	return 0;
}