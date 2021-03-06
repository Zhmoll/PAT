#include <cstdio>
#include <algorithm>
using namespace std;
struct Fraction {
	long long up, down;
	Fraction() { up = 0; down = 1; }
	Fraction(long long up, long long down) :up(up), down(down) {}
};

long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a%b);
}

Fraction Reduction(Fraction a) {
	if (a.up == 0) {
		a.down = 1;
		return a;
	}
	if (a.down < 0) {
		a.up = -a.up;
		a.down = -a.down;
	}
	long long d = GCD(abs(a.up), a.down);
	a.up /= d;
	a.down /= d;
	return a;
}

Fraction Plus(Fraction a, Fraction b) {
	Fraction result;
	result.down = a.down * b.down;
	result.up = a.up * b.down + a.down *b.up;
	return Reduction(result);
}

Fraction Minus(Fraction a, Fraction b) {
	b.up = -b.up;
	return Plus(a, b);
}

Fraction Product(Fraction a, Fraction b) {
	Fraction result;
	result.up = a.up * b.up;
	result.down = a.down * b.down;
	return Reduction(result);
}

Fraction Quo(Fraction a, Fraction b) {
	swap(b.up, b.down);
	return Product(a, b);
}

void Print(Fraction a) {
	a = Reduction(a);
	if (a.down == 0) {
		printf("Inf");
		return;
	}
	if (a.down == 1) {
		if (a.up < 0)printf("(");
		printf("%lld", a.up);
		if (a.up < 0)printf(")");
		return;
	}
	if (abs(a.up) > a.down) {
		if (a.up < 0)printf("(");
		printf("%lld %lld/%lld", a.up / a.down, abs(a.up) % a.down, a.down);
		if (a.up < 0)printf(")");
		return;
	}
	else {
		if (a.up < 0)printf("(");
		printf("%lld/%lld", a.up, a.down);
		if (a.up < 0)printf(")");
	}
}

int main() {
	Fraction a, b;
	scanf("%lld/%lld", &a.up, &a.down);
	scanf("%lld/%lld", &b.up, &b.down);

	Print(a);
	printf(" + ");
	Print(b);
	printf(" = ");
	Print(Plus(a, b));
	printf("\n");

	Print(a);
	printf(" - ");
	Print(b);
	printf(" = ");
	Print(Minus(a, b));
	printf("\n");

	Print(a);
	printf(" * ");
	Print(b);
	printf(" = ");
	Print(Product(a, b));
	printf("\n");

	Print(a);
	printf(" / ");
	Print(b);
	printf(" = ");
	Print(Quo(a, b));
	printf("\n");

	return 0;
}