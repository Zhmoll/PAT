#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int NC,NP;
	scanf("%d", &NC);
	vector<int> coupon(NC);
	for (int i = 0; i < NC; i++) {
		scanf("%d", &coupon[i]);
	}

	scanf("%d", &NP);
	vector<int> product(NP);
	for (int i = 0; i < NP; i++) {
		scanf("%d", &product[i]);
	}

	sort(coupon.begin(), coupon.end());
	sort(product.begin(), product.end());

	int sum = 0;
	int i = 0, j = 0;// i指向coupon，j指向product
	// 处理小于0的
	while (i<NC && coupon[i] < 0) {
		// 要搭配负数的product
		if (j<NP && product[j] < 0) {
			sum += coupon[i] * product[j];
			i++;
			j++;
		}
		else {
			break;
		}
	}

	i = NC - 1;
	j = NP - 1;
	// 处理大于0的
	while (i >= 0 && coupon[i] > 0) {
		// 要搭配正数的product
		if (j >= 0 && product[j] > 0) {
			sum += coupon[i] * product[j];
			i--;
			j--;
		}
		else {
			break;
		}
	}
	printf("%d", sum);
	return 0;
}