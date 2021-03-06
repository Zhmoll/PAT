#include <cstdio>
#include <string>
using namespace std;

void gen(int num, string &s) {
	while (num != 0) {
		int bit = num % 13;
		switch (bit) {
		case 10: {s.insert(0, "A"); break; }
		case 11: {s.insert(0, "B"); break; }
		case 12: {s.insert(0, "C"); break; }
		default: s.insert(0, to_string(bit));
			break;
		}
		num /= 13;
	}
	while (s.length() < 2)
		s.insert(0, "0");
}

int main() {
	int r, g, b;
	scanf("%d %d %d", &r, &g, &b);
	string marsR, marsG, marsB;
	gen(r, marsR);
	gen(g, marsG);
	gen(b, marsB);
	printf("#%s%s%s", marsR.c_str(), marsG.c_str(), marsB.c_str());
	return 0;
}