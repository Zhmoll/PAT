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

void Print(Fraction a) {
	a = Reduction(a);
	if (a.down == 1) {
		printf("%lld", a.up);
		return;
	}
	if (abs(a.up) > a.down) {
		printf("%lld %lld/%lld", a.up / a.down, abs(a.up) % a.down, a.down);
		return;
	}
	else {
		printf("%lld/%lld", a.up, a.down);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	int up, down;
	Fraction sum;
	for (int i = 0; i < N; i++) {
		scanf("%d/%d", &up, &down);
		sum = Plus(sum, Fraction(up, down));
	}
	Print(sum);
	return 0;
}