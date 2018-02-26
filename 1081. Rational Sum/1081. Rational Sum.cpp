#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Fraction {
	long long up, down;
	Fraction() :up(0), down(1) {};
};

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

Fraction reduce(Fraction result) {
	if (result.down < 0) {
		result.down = -result.down;
		result.up = -result.up;
	}
	if (result.up == 0) {
		result.down = 1;
	}
	else {
		long long d = gcd(result.up, result.down);
		result.up /= d;
		result.down /= d;
	}
	return result;
}

Fraction add(Fraction a, Fraction b) {
	Fraction result;
	result.down = a.down * b.down;
	result.up = a.up * b.down + b.up * a.down;
	result = reduce(result);
	return result;
}

int main() {
	int N;
	scanf("%d", &N);
	Fraction suma, tmp;
	for (int i = 0; i < N; i++) {
		scanf("%lld/%lld", &tmp.up, &tmp.down);
		suma = add(tmp, suma);
	}
	if (suma.down == 1) printf("%lld", suma.up);
	else if (abs(suma.up) > suma.down) {
		printf("%lld %lld/%lld", suma.up / suma.down, abs(suma.up) % suma.down, suma.down);
	}
	else {
		printf("%lld/%lld", suma.up, suma.down);
	}
	return 0;
}