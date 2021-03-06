#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Fraction {
	long long up, down;
};

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	else return gcd(b, b%a);
}

Fraction Freduction(Fraction a) {
	if (a.up == 0) {
		a.down = 1;
		return a;
	}
	if (a.down < 0) {
		a.up = -a.up;
		a.down = -a.down;
	}
	long long d = gcd(abs(a.up), abs(a.down));
	a.up /= d;
	a.down /= d;
	return a;
}

Fraction Fplus(Fraction a, Fraction b) {
	Fraction result;
	result.down = a.down * b.down;
	result.up = a.up*b.down + a.down*b.up;
	return Freduction(result);
}

Fraction Fminus(Fraction a, Fraction b) {
	b.up = -b.up;
	return Fplus(a, b);
}

Fraction Fproduct(Fraction a, Fraction b) {
	Fraction result;
	result.up = a.up*b.up;
	result.down = a.down*b.down;
	return Freduction(result);
}

Fraction Fquo(Fraction a, Fraction b) {
	swap(b.up, b.down);
	return Fproduct(a, b);
}

void Fprint(Fraction a) {
	a = Freduction(a);
	if (a.down == 1) printf("%lld", a.up);
	else if (abs(a.up) > a.down) {
		printf("%lld %lld/%lld", a.up / a.down, abs(a.up) % a.down, a.down);
	}
	else {
		printf("%lld/%lld", a.up, a.down);
	}
}

int main() {

	return 0;
}