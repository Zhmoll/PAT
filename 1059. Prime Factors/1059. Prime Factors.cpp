#include <cstdio>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

bool isPrime(long long num) {
	long long compare = sqrt(num);
	bool flag = true;
	for (int i = 2; i <= compare; i++) {
		if (num % i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
}

int main() {
	long long N = 0;
	scanf("%lld", &N);

	map<int, int> Prime;

	for (int i = 2; i <= sqrt(N); i++) {
		if (isPrime(i)) {
			Prime.insert(make_pair(i, 0));
		}
	}

	long long source = N;
	map<int, int>::iterator it = Prime.begin();
	int count = 0;
	while (it != Prime.end()) {
		if (N % it->first == 0) {
			it->second++;
			N /= it->first;
			count++;
		}
		else {
			it++;
		}
	}

	printf("%lld=", source);

	it = Prime.begin();
	int new_count = 0;
	for (int i = 0; i < count, it != Prime.end(); it++) {
		if (it->second == 1) {
			printf("%d", it->first);
			new_count += it->second;
			if (i != count - 1 && new_count < count) printf("*");
		}
		else if (it->second > 1) {
			printf("%d^%d", it->first, it->second);
			new_count += it->second;
			if (i != count - 1 && new_count < count) printf("*");
		}
	}

	if (N != 1 || source == 1) {
		if (count != 0) printf("*");
		printf("%lld", N);
	};
	return 0;
}