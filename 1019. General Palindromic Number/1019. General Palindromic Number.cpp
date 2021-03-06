#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N = 0, b = 0;
	scanf("%d%d", &N, &b);

	vector<int> digi;
	if (N == 0) {
		digi.push_back(0);
	}
	int tmp = 0;
	while (N != 0) {
		tmp = N % b;
		N = N / b;
		digi.push_back(tmp);
	}

	vector<int> digi_re = digi;
	reverse(digi_re.begin(), digi_re.end());

	bool flag = true;
	for (int i = 0; i < digi.size(); i++) {
		if (digi[i] != digi_re[i]) {
			flag = false;
			break;
		}
	}

	if (flag)
		printf("Yes\n");
	else
		printf("No\n");

	for (int i = 0; i < digi_re.size(); i++) {
		printf("%d", digi_re[i]);
		if (i != digi_re.size() - 1) printf(" ");
	}
	return 0;
}