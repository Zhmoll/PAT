#include <cstdio>
#include <cmath>
using namespace std;
struct Fraction {
	long long up, down;
	// Fraction(long long up, long long down) :up(up), down(down) {};
};

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

Fraction reduce(Fraction result) {
	if (result.down < 0) {
		result.up = -result.up;
		result.down = -result.down;
	}
	if (result.up == 0) {
		result.down = 1;
	}
	else {
		long long num = gcd(abs(result.up), abs(result.down));
		result.up /= num;
		result.down /= num;
	}
	return result;
}

Fraction plus(Fraction a, Fraction b) {
	Fraction result;
	result.down = a.down * b.down;
	result.up = a.up*b.down + b.up*a.down;
	return reduce(result);
}

Fraction diff(Fraction a, Fraction b) {
	b.up = -b.up;
	return plus(a, b);
}

Fraction prod(Fraction a, Fraction b) {
	Fraction result;
	result.up = a.up*b.up;
	result.down = a.down*b.down;
	return reduce(result);
}

Fraction quo(Fraction a, Fraction b) {
	long long tmp = b.up;
	b.up = b.down;
	b.down = tmp;
	return prod(a, b);
}

void print(Fraction a) {
	a = reduce(a);
	if (a.down == 0) {
		printf("Inf");
		return;
	}
	if (a.up < 0) printf("(");

	if (a.down == 1) {
		printf("%lld", a.up);
	}
	else if (abs(a.up) > a.down) {
		long long num = a.up;
		if (a.up < 0) num = -a.up;
		printf("%lld %lld/%lld", a.up / a.down, num%a.down, a.down);
	}
	else {
		printf("%lld/%lld", a.up, a.down);
	}

	if (a.up < 0) printf(")");
}

int main() {
	Fraction a, b;
	scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
	// plus
	print(a);
	printf(" + ");
	print(b);
	printf(" = ");
	print(plus(a, b));
	printf("\n");
	// diff
	print(a);
	printf(" - ");
	print(b);
	printf(" = ");
	print(diff(a, b));
	printf("\n");
	// prod
	print(a);
	printf(" * ");
	print(b);
	printf(" = ");
	print(prod(a, b));
	printf("\n");
	// quo
	print(a);
	printf(" / ");
	print(b);
	printf(" = ");
	print(quo(a, b));
	printf("\n");
	return 0;
}